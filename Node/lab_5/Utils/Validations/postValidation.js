import Joi from "joi";
import mongoose from "mongoose";

const postValidationSchema = Joi.object({
    title: Joi.string().min(3).max(50).required().messages({
        "string.min": "Title must be at least 3 characters long",
        "string.max": "Title must be at most 50 characters long",
        "string.empty": "Title is required",
    }),

    content: Joi.string().min(3).max(1000).required().messages({
        "string.min": "Content must be at least 3 characters long",
        "string.max": "Content must be at most 1000 characters long",
        "string.empty": "Content is required",
    })
});

export default postValidationSchema;