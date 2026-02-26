
import bcrypt from "bcrypt"

let hashPassword = (req,res,next) => {
    req.body.password = bcrypt.hashSync(req.body.password, 10)
    next();
}

export default hashPassword;