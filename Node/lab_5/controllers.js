const fs = require("fs");
const { validatePost, validateId } = require("./validations")

exports.getAllPosts = (req, res) => {
    if (!fs.existsSync("posts.json")) {
        res.statusCode = 204;
        return res.end();
    } else {
        const data = fs.readFileSync("posts.json", "utf-8");
        const posts = JSON.parse(data || "[]");
        if (posts.length === 0) {
            res.statusCode = 204;
            return res.end();
        }
        res.setHeader("Content-Type", "application/json");
        res.end(JSON.stringify(posts));
    }
}

exports.getPostById = (req, res, id) => {
    try {
        if (!fs.existsSync("posts.json")) {
            res.statusCode = 204;
            return res.end();
        }
        if (isNaN(id)) {
            res.statusCode = 400;
            return res.end("Invalid post ID");
        }
        const data = fs.readFileSync("posts.json", "utf-8");
        const posts = JSON.parse(data || "[]");
        const post = posts.find(p => p.id == id);

        if (!post) {
            res.statusCode = 404;
            return res.end("Post not found");
        }

        res.statusCode = 200;
        res.setHeader("Content-Type", "application/json");
        res.end(JSON.stringify(post, null, 2));

    } catch (err) {
        res.statusCode = 500;
        res.end("Server Error");
    }
}

exports.createPost = (req, res) => {
    req.on("data", (chunk) => {
        const newPost = JSON.parse(chunk);

        if (!validatePost(newPost)) {
            res.statusCode = 400;
            return res.end("Invalid data in body");
        }

        newPost.createdAt = new Date().toISOString();
        try {
            let posts = [];

            if (!fs.existsSync("posts.json")) {
                posts.push(newPost);
                fs.writeFileSync("posts.json", JSON.stringify(posts, null, 2));

                res.statusCode = 201;
                res.setHeader("Content-Type", "application/json");
                return res.end("Post Created");
            }

            const data = fs.readFileSync("posts.json", "utf-8");
            posts = JSON.parse(data || "[]");
            const isPostExisted = posts.find(element => element.id == newPost.id);

            if (isPostExisted) {
                res.statusCode = 400;
                return res.end("Post Already Exists");
            } else {
                posts.push(newPost);
                fs.writeFileSync("posts.json", JSON.stringify(posts, null, 2));

                res.statusCode = 201;
                res.end("Post Created");
            }
        }
        catch (err) {
            res.statusCode = 500;
            res.end("Server Error");
        }
    });
}

exports.updatePost = (req, res) => {
    req.on("data", (chunk) => {
        let updatedPost = JSON.parse(chunk);
        if(!validatePost(updatedPost)){
            res.statusCode = 400;
            return res.end("Invalid data in body");
        }
        try {
            if (!fs.existsSync("posts.json")) {
                res.statusCode = 500;
                return res.end("Server error");
            }

            const data = fs.readFileSync("posts.json", "utf-8");
            let posts = JSON.parse(data || "[]");

            const post = posts.find(p => p.id == updatedPost.id);
            if (!post) {
                res.statusCode = 404;
                return res.end("Post not found");
            }

            post.title = updatedPost.title;
            post.content = updatedPost.content;
            post.updatedAt = new Date().toISOString();

            fs.writeFileSync("posts.json", JSON.stringify(posts, null, 2));

            res.statusCode = 200;
            res.end("Post Updated");

        } catch {
            res.statusCode = 500;
            res.end("Server Error");
        }
    })
}

exports.deletePost = (req, res) => {
    req.on("data", (chunk) => {
        const delPost = JSON.parse(chunk);
        if (!delPost || !validateId(delPost.id)) {
            res.statusCode = 400;
            return res.end("Post id is not valid");
        }
        try {
            if (!fs.existsSync("posts.json")) {
                res.statusCode = 404;
                return res.end("No posts file exists");
            }

            const data = fs.readFileSync("posts.json", "utf-8");
            let posts = JSON.parse(data || "[]");

            const postSizeBeforeDelete = posts.length;
            posts = posts.filter(p => p.id !== delPost.id);

            if (posts.length === postSizeBeforeDelete) {
                res.statusCode = 404;
                return res.end("Post with that ID does not exist");
            }

            fs.writeFileSync("posts.json", JSON.stringify(posts, null, 2));

            res.statusCode = 200;
            res.end("Post Deleted");

        } catch {
            res.statusCode = 500;
            res.end("Server Error");
        }
    })
}