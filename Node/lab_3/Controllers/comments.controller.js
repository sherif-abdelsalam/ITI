import commentsModel from "../Models/Comment.model.js";
import postsModel from "../Models/Post.model.js";


export const createComment = async (req, res) => {
    try{
        const id = req.params.id;
        const post = await postsModel.findById(id);
        if (!post) {
            return res.status(404).json({
                message: "Post Not Found"
            });
        }
        
        if (!validateComment({content: req.body.content})) {
            return res.status(400).json({
                message: "Invalid Comment Data"
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

    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const getAllComments = async (req, res) => {
    try{
        const comments = await commentsModel.find().populate("owner", "name email").populate("post", "title");
        res.status(200).json({
            message: "List Of Comments",
            length: comments.length,
            data: comments
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const getComment = async (req, res) => {
    try{
        const comment = await commentsModel.findById(req.params.id).populate("owner", "name email").populate("post", "title");
        if (!comment) {
            return res.status(404).json({
                message: "Comment Not Found"
            });
        }
        res.status(200).json({
            message: "Comment",
            data: comment
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const deleteComment = async (req, res) => {
    try{
        await req.comment.deleteOne();
        res.status(200).json({
            message: "Comment Deleted",
            data: req.comment
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const updateComment = async (req, res) => {
    try{
        if (!validateComment({content: req.body.content})) {
            return res.status(400).json({
                message: "Invalid Comment Data"
            });
        }
        req.comment.content = req.body.content;
        const newUpdatedComment = await req.comment.save();
        res.status(200).json({
            message: "Comment Updated",
            data: newUpdatedComment
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}