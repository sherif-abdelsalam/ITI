
import userModel from "../Models/User.model.js"
import bcrypt from "bcrypt"
import jwt from "jsonwebtoken"

import { sendEmail } from "../Utils/Email/sendEmail.js"
import catchError from "../Middleware/catchError.js"

const signToken = (id, role, email) => {
    return jwt.sign({ _id: id, role: role, email: email }, process.env.JWT_SECRET)
}

const signup = catchError(async (req, res) => {
    let newUser = await userModel.create({
        name: req.body.name,
        email: req.body.email,
        password: req.body.password,
        age: req.body.age
    });
    await sendEmail(req.body.email)
    // const token = signToken(newUser._id, newUser.role, newUser.email);
    newUser.password = undefined;
    res.json({
        message: {
            "success": "User Created Successfully",
            "email": "Please Verify Your Email"
        }, data: newUser
    })
});


const signin = catchError(async (req, res) => {
    let foundUser = req.foundUser;
    let matchPassword = bcrypt.compareSync(req.body.password, foundUser.password);
    if (matchPassword) {
        const token = signToken(foundUser._id, foundUser.role, foundUser.email);
        foundUser.password = undefined;
        return res.json({ message: "Welcome", data: foundUser, token: token });
    }
    res.status(422).json({ message: "Invalid Password or Email" });

}
);


const getMyAccount = catchError(async (req, res) => {
    const myAccount = await userModel.findById(req.decodedUser._id);
    if (!myAccount) {
        return res.status(404).json({ message: "User Not Found" })
    }
    myAccount.password = undefined;
    res.status(200).json({ message: "My Account", data: myAccount });
}
);
const verifyAccount = catchError(async (req, res) => {
    console.log(req.params);
    let verifyEmail = req.params.email;
    console.log(verifyEmail);
    jwt.verify(verifyEmail, process.env.JWT_SECRET, async (err, decoded) => {
        if (err) {
            return res.status(401).json({ message: "Invalid Token" })
        }
        await userModel.findOneAndUpdate({ email: decoded }, { isConfirmed: true })
        res.status(200).json({ message: "Account Verified" })
    })
});

export { signup, signin, verifyAccount, getMyAccount };