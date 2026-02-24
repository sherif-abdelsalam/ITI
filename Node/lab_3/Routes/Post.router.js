import { Router } from "express";

import { createPost, getAllPosts, getPost, updatePost, deletePost } from "../Controllers/posts.controller.js";

const router = Router();

router.post("/", createPost)
router.get("/", getAllPosts)
router.get("/:id", getPost)
router.put("/:id", updatePost)
router.delete("/:id", deletePost)

export default router;