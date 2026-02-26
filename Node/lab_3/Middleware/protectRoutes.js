import jwt from 'jsonwebtoken';

export const protect = (req, res, next) => {
    try{

        let token = req.headers.token;
        jwt.verify(token, process.env.JWT_SECRET, async (err, decoded) => {
            if (err) {
                return res.status(401).json({ message: "Invalid Token" })
            } else {
                req.decodedUser = decoded;
                next();
            }
        })
    }catch(err){
        res.status(500).json({message: err.message})
    }
};