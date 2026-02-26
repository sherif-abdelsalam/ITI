import { Router } from "express";

const router = Router();
import { protect } from "../Middleware/protectRoutes.js";
import { createComment } from "../Controllers/comments.controller.js";

router.use(protect);

router.post("/", createComment);

export default router;