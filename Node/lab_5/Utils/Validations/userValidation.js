
import Joi from "joi";


const userValidationSchema =  Joi.object({
    name: Joi.string().min(3).max(10).required().messages({
        "string.min": "Name must be at least 3 characters long",
        "string.empty": "Name is required",
    }),
    email: Joi.string().email().required().messages({
        "string.email": "Invalid Email",
    }),
    password: Joi.string().required().pattern(new RegExp('^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z]).{8,16}$')).messages({
        "string.pattern.base": "Password must contain at least one uppercase letter, one lowercase letter, and one number",
    }), 
    age: Joi.number().integer().min(20).max(50).required().messages({
        "number.base": "Age must be a number",
        "number.integer": "Age must be an integer",
        "number.min": "Age must be at least 20",
        "number.max": "Age must be at most 50",
        "number.empty": "Age is required",
    })
})

const signInSchema = Joi.object({
    email: Joi.string().email().required().messages({
        "string.email": "Invalid Email",
    }),
    password: Joi.string().required().pattern(new RegExp('^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z]).{8,16}$')).messages({
        "string.pattern.base": "Password must contain at least one uppercase letter, one lowercase letter, and one number",
    }),
})


export {userValidationSchema, signInSchema};