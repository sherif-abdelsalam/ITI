import express from "express"
import path from "path"
import { fileURLToPath } from "url";

import { validateInt, validateComment } from "./validations.js"

const __dirname = path.dirname(fileURLToPath(import.meta.url));

let comments = [
    { id: 1, author: "sherif mohamed", body: "this is the first comment" },
    { id: 2, author: "ali mohamed", body: "this is the second comment" },
    { id: 3, author: "ahmed mohamed", body: "this is the third comment" }
]



const app = express();
app.use(express.json());
app.use(express.static(path.join(__dirname, "assets")));


app.get("/home", (req, res) => {
    const indexPath = path.join(__dirname,  "assets", "index.html");
    res.sendFile(indexPath);
})


app.get("/comments", (req, res) => {
    res.status(200).json(comments);
})

app.get("/comments/:id", (req, res) => {
    const { id } = req.params;
    if (!validateInt(id)) {
        return res.status(400).json({ error: "invalid id" });
    }

    const comment = comments.find(comment => comment.id == id);
    if (!comment) {
        return res.status(404).json({ error: "comment not found" });
    }

    res.status(200).json(comment);
})

app.post("/comments", (req, res) => {
    const comment = req.body;
    if (!validateComment(comment)) {
        return res.status(400).json({ error: "invalid comment data" });
    }
    const newComment = {
        id : comments.length ? comments[comments.length - 1].id + 1 : 1,
        author : comment.author,
        body : comment.body
    }
    comments.push(newComment);
    res.status(201).json(newComment);
})

app.put("/comments/:id", (req, res) => {
    const { id } = req.params;
    if (!validateInt(id)) {
        return res.status(400).json({ error: "invalid id" });
    }   
    if (!validateComment(req.body)) {
        return res.status(400).json({ error: "invalid comment data" });
    }
    const comment = comments.find(comment => comment.id == req.params.id);
    if (!comment) {
        return res.status(404).json({ error: "comment not found" });
    }
    const index = comments.indexOf(comment);
    const updatedComment = {
        id : comment.id,
        author : req.body.author,
        body : req.body.body
    }
    comments[index] = updatedComment;
    res.status(200).json(updatedComment);
})

app.delete("/comments/:id", (req, res) => {

    const { id } = req.params;
    if (!validateInt(id)) {
        return res.status(400).json({ error: "invalid id" });
    }
    const sizeBefore = comments.length;
    comments = comments.filter(comment => comment.id != id);
    if (comments.length == sizeBefore) {
        return res.status(404).json({ error: "comment not found" });
    }    res.status(200).send("comment deleted");
})

app.listen(4000, () => {
    console.log("Server up and running on port 4000");
})