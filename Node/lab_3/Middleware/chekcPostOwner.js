import postModel from "../Models/Post.model.js";

export const checkPostOwner = async (req, res, next) => {

    try {

        const post = await postModel.findById(req.params.id);

        if (!post) {
            return res.status(404).json({
                message: "Post Not Found"
            });

        }

        if (post.owner.toString() !== req.decodedUser._id) {
            return res.status(403).json({
                message: "You Don't Have Permission To update/delete This Post"
            });

        }

        req.post = post;
        next();

    } catch (error) {

        res.status(500).json({
            message: error.message
        });

    }

};