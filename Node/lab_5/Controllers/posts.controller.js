import catchError from "../Middleware/catchError.js";
import postModel from "../Models/Post.model.js";

export const getAllPosts = catchError(async (req, res) => {
    const posts = await postModel.find().select("title content").populate("owner", "name email");
    if (!posts) { return res.status(404).json({ message: "No Posts Found" }); }
    res.status(200).json({
        message: "List Of Posts",
        length: posts.length,
        data: posts
    });

});

export const getMyPosts = catchError(async (req, res) => {
    const posts = await postModel.find({ owner: req.decodedUser._id }).select("title content");
    if (!posts) { return res.status(404).json({ message: "No Posts Found" }); }
    res.status(200).json({
        message: "My Posts List",
        length: posts.length,
        data: posts
    });
});

export const getPost = catchError(async (req, res) => {
    const post = await postModel.findById(req.params.id).populate("owner", "name email");
    if (!post) { return res.status(404).json({ message: "Post Not Found" }); }
    res.status(200).json({
        message: "Post",
        data: post
    });
})

export const createPost = catchError(async (req, res) => {
    let newPost = {
        title: req.body.title,
        content: req.body.content,
        owner: req.decodedUser._id
    };

    newPost = await postModel.create(newPost);
    res.status(201).json({
        message: "Post Created",
        data: newPost
    });
})

export const updatePost = catchError(async (req, res) => {
    let updatedPost = {
        title: req.body.title,
        content: req.body.content
    };
    req.post.title = updatedPost.title;
    req.post.content = updatedPost.content;
    const newUpdatedPost = await req.post.save();

    res.status(200).json({
        message: "Post Updated",
        data: newUpdatedPost
    });


})

export const deletePost = catchError(async (req, res) => {
    await req.post.deleteOne();
    res.status(200).json({
        message: "Post Deleted",
        data: req.post
    });
})