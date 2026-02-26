import { Router } from "express";

import { createPost, getAllPosts, getPost, updatePost, deletePost, getMyPosts } from "../Controllers/posts.controller.js";
import { protect } from "../Middleware/protectRoutes.js";
import { checkPostOwner } from "../Middleware/chekcPostOwner.js";

const router = Router();


router.use(protect);

router.get("/", getAllPosts);
router.post("/", createPost);
router.get("/myposts", getMyPosts);
router.get("/:id", getPost);
router.put("/:id",checkPostOwner ,updatePost);
router.delete("/:id", checkPostOwner, deletePost);

export default router;