import commentValidationSchema from "../Utils/Validations/commentValidaion.js";
import postValidationSchema from "../Utils/Validations/postValidation.js";
import {signInSchema, userValidationSchema} from "../Utils/Validations/userValidation.js";

export const validationMiddleware =  (req,res,next) => {
    const {error} = userValidationSchema.validate(req.body);
    if(error){
        return res.status(422).json({message: error.details[0].message})
    }
    next();
}

export const signinValidationMiddleware =  (req,res,next) => {
    const {error} = signInSchema.validate(req.body);
    if(error){
        return res.status(422).json({message: error.details[0].message})
    }
    next();
}


export const validatePost = (req,res,next) => {
    const {error} = postValidationSchema.validate(req.body);
    if(error){
        return res.status(422).json({message: error.details[0].message})
    }
    next();
}

export const validateComment = (req,res,next) => {
    const {error} = commentValidationSchema.validate(req.body);
    if(error){
        return res.status(422).json({message: error.details[0].message})
    }
    next();
}