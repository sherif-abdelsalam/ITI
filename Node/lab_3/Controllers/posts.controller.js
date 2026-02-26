import postModel from "../Models/Post.model.js";
import { validatePost } from "../Utils/post_validaion.js";

export const getAllPosts = async (req, res) => {
    try {
        const posts = await postModel.find().select("title content").populate("owner", "name email");

        res.status(200).json({
            message: "List Of Posts",
            length: posts.length,
            data: posts
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }
}

export const getMyPosts = async (req, res) => {
    try {
        console.log(req.decodedUser);
        const posts = await postModel.find({ owner: req.decodedUser._id }).populate("owner", "name");

        res.status(200).json({
            message: "My Posts List",
            length: posts.length,
            data: posts
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }
}

export const getPost = async (req, res) => {
    try {
        
        const post = await postModel.findById(req.params.id).populate("owner", "name email");
        if (!post) {
            return res.status(404).json({ message: "Post Not Found" });
        }

        res.status(200).json({
            message: "Post",
            data: post
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }

}

export const createPost = async (req, res) => {
    try {
        let newPost = {
            title: req.body.title,
            content: req.body.content,
            owner: req.decodedUser._id
        };

        if (!validatePost(newPost)) {
            return res.status(400).json({
                message: "Invalid Post Data"
            });
        }

        newPost = await postModel.create(newPost);
        res.status(201).json({
            message: "Post Created",
            data: newPost
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }

}

export const updatePost = async (req, res) => {

    try {
        let updatedPost = {
            title: req.body.title,
            content: req.body.content
        };
        
        if(!validatePost(updatedPost)){
            return res.status(400).json({ message: "Invalid Post Data"});
        }

        req.post.title = updatedPost.title;
        req.post.content = updatedPost.content;
        const newUpdatedPost = await req.post.save(); 

        res.status(200).json({
            message: "Post Updated",
            data: newUpdatedPost
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }

}

export const deletePost = async (req, res) => {

    try {
        await req.post.deleteOne();
        res.status(200).json({
            message: "Post Deleted",
            data: req.post
        });

    } catch (error) {
        res.status(500).json({ message: error.message });
    }
}