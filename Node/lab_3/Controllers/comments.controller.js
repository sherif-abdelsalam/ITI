import commentsModel from "../Models/Comment.model.js";
import postsModel from "../Models/Post.model.js";

import { validateComment } from "../Utils/validation.js";

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

export const getPostComments = async (req, res) => {
    try{
        const comments = await commentsModel.find({post: req.params.id}).populate("owner", "name email").populate("post", "title");
        res.status(200).json({
            message: "List Of Comments",
            length: comments.length,
            data: comments
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const getMyComment = async (req, res) => {
    try{
        const comment = await commentsModel.findOne({owner: req.decodedUser._id}).populate("post", "title");
        if (!comment) {
            return res.status(404).json({
                message: "Comments Not Found"
            });
        }
        res.status(200).json({
            message: "My Comment",
            data: comment
        });
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const deleteComment = async (req, res) => {
    try{
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
    }catch(err){
        res.status(500).json({message: err.message})
    }
}

export const updateComment = async (req, res) => {
    try{
        
        if (!validateComment(req.body)) {
            return res.status(400).json({
                message: "Invalid Comment Data"
            });
        }

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
    }catch(err){
        res.status(500).json({message: err.message})
    }
}