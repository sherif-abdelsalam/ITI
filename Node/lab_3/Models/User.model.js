import mongoose from "mongoose";

const userSchema = new mongoose.Schema({
    name:{
        type: String,
        minlength: 3, 
        maxlength: 10
    },
    email: {
        type: String,
        unique: true
    }, 
    password: {
        type: String,
        required: true 
    },
    age: {
        type: Number,
        min: 20,
        max: 50
    },
    role: {
        type: String,
        enum: ["user", "admin"],
        default: "user"
    }
},{
    timestamps: true, 
    versionKey: false 
})

const userModel =   mongoose.model("User", userSchema);

export default userModel