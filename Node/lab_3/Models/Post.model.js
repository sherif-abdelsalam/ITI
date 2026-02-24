import mongoose from "mongoose";

const postSchema = new mongoose.Schema({

    title: {
        type: String,
        required: true
    },
    content: {
        type: String,
        required: true
    }
}, {
    timestamps: true
})

const postsModel = mongoose.model("posts", postSchema)
export default postsModel;
