import { Router } from "express";

import { createPost, getAllPosts, getPost, updatePost, deletePost, getMyPosts } from "../Controllers/posts.controller.js";
import { createComment, updateComment, deleteComment, getPostComments, getMyComment } from "../Controllers/comments.controller.js";
import { protect } from "../Middleware/protectRoutes.js";
import { checkPostOwner } from "../Middleware/chekcPostOwner.js";
import { validateComment, validatePost } from "../Middleware/validation.js";

const router = Router();


router.use(protect);

router.get("/", getAllPosts);
router.post("/",validatePost , createPost);
router.get("/myposts", getMyPosts);
router.get("/:id", getPost);
router.put("/:id",checkPostOwner ,updatePost);
router.delete("/:id", checkPostOwner, deletePost);

// comments 
router.post("/:id/comments", validateComment, createComment);
router.get("/:id/comments", getPostComments);
router.get("/:id/mypostcomment", getMyComment);
router.put("/:id/comments/:commentId", checkPostOwner, updateComment);
router.delete("/:id/comments/:commentId", checkPostOwner, deleteComment);   

export default router;