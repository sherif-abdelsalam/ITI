import { Router } from "express";

const router = Router();

import { signup, signin } from "../Controllers/auth.controller.js";
import checkEmail from "../Middleware/checkEmail.js";
import hashPassword from "../Middleware/hashPassword.js";

router.use(checkEmail);
router.post("/signup", hashPassword, signup);
router.post("/signin", signin);

export default router;