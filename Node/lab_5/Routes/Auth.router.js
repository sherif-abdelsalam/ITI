import { Router } from "express";

const router = Router();

import { signup, signin , verifyAccount, getMyAccount} from "../Controllers/auth.controller.js";
import checkEmail from "../Middleware/checkEmail.js";
import hashPassword from "../Middleware/hashPassword.js";
import {protect} from "../Middleware/protectRoutes.js"  
import {validationMiddleware, signinValidationMiddleware} from "../Middleware/validation.js"

router.post("/signup",validationMiddleware, checkEmail, hashPassword, signup);
router.post("/signin", signinValidationMiddleware, checkEmail, signin);
router.get("/verify/:email", verifyAccount);
router.get("/myaccount", protect, getMyAccount);

export default router;