import Joi from "joi";

const commentValidationSchema = Joi.object({
    content: Joi.string().min(3).max(1000).required().messages({
        "string.min": "Content must be at least 3 characters long",
        "string.max": "Content must be at most 1000 characters long",
        "string.empty": "Content is required",
    })
});

export default commentValidationSchema;