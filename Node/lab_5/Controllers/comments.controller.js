import catchError from "../Middleware/catchError.js";
import commentsModel from "../Models/Comment.model.js";
import postsModel from "../Models/Post.model.js";

export const createComment = catchError(async (req, res) => {
    const id = req.params.id;
    const post = await postsModel.findById(id);
    if (!post) {
        return res.status(404).json({
            message: "Post Not Found"
        });
    }

    let newComment = {
        content: req.body.content,
        owner: req.decodedUser._id,
        post: id
    };

    newComment = await commentsModel.create(newComment);
    res.status(201).json({
        message: "Comment Created",
        data: newComment
    });

});

export const getPostComments = catchError(async (req, res) => {
    const comments = await commentsModel.find({ post: req.params.id }).populate("owner", "name email").populate("post", "title");
    res.status(200).json({
        message: "List Of Comments",
        length: comments.length,
        data: comments
    });
});

export const getMyComment = catchError(async (req, res) => {
    const comment = await commentsModel.findOne({ owner: req.decodedUser._id, post: req.params.id }).populate("post", "title");
    if (!comment) {
        return res.status(404).json({
            message: "Comments Not Found"
        });
    }
    res.status(200).json({
        message: "My Comment",
        data: comment
    });
});

export const deleteComment = catchError(async (req, res) => {
    let comment = await commentsModel.findById(req.params.commentId);
    if (!comment) {
        return res.status(404).json({
            message: "Comment Not Found"
        });
    }
    await comment.deleteOne();
    res.status(200).json({
        message: "Comment Deleted",
        data: comment
    });

});

export const updateComment = catchError(async (req, res) => {

    let comment = await commentsModel.findById(req.params.commentId);
    if (!comment) {
        return res.status(404).json({
            message: "Comment Not Found"
        });
    }
    comment.content = req.body.content;
    comment = await comment.save();
    res.status(200).json({
        message: "Comment Updated",
        data: comment
    });

});