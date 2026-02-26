
import userModel from "../Models/User.model.js"
import bcrypt from "bcrypt"
import jwt from "jsonwebtoken"

const signToken = (id, role, email) => {
    return jwt.sign({_id: id, role: role, email: email}, process.env.JWT_SECRET)
}

const signup = async (req, res) => {
    try{

        let newUser = await userModel.create({
            name: req.body.name,
            email: req.body.email,
            password: req.body.password,
            age: req.body.age
        }); 
        const token = signToken(newUser._id, newUser.role, newUser.email);
        newUser.password = undefined;
        res.json({message: "User Added", data: newUser, token})
    }catch(err){
        res.status(500).json({message: err.message})
    }
}


const signin = async (req, res) => {
    try{
        let foundUser = req.foundUser; 
        let matchPassword = bcrypt.compareSync(req.body.password, foundUser.password);
        if(matchPassword){
            const token = signToken(foundUser._id, foundUser.role, foundUser.email);
            foundUser.password = undefined;
            return res.json({message: "Welcome", data: foundUser, token: token});
        }
        res.status(422).json({message: "Invalid Password or Email"});
    }catch(err){
        res.status(500).json({message: err.message});
    }
}

export {signup, signin};