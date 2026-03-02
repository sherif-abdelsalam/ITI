import dotenv from "dotenv"
dotenv.config();
import express from "express"

import { db_connect } from "./Database/dbConnect.js";
import postsRouter from "./Routes/Post.router.js";
// import commentsRouter from "./Routes/Comment.router.js";
import authRouter from "./Routes/Auth.router.js";


const app = express();
app.use(express.json());
await db_connect(); 

app.use("/posts", postsRouter);
// app.use("/comments", commentsRouter);
app.use("/", authRouter);


app.listen(4000, () => {
    console.log("Server running on port 4000");
});