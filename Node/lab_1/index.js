const http = require("http");
const { getAllPosts, updatePost, deletePost, createPost, getPostById } = require("./controllers.js");


const server = http.createServer((req, res) => {
    if (req.url == "/") {
        res.end("welcome");
    } else if ((req.url == "/posts" || req.url == "/posts/") && req.method == "GET") {
        getAllPosts(req, res);
    } else if (req.url.startsWith("/posts/") && req.method === "GET") {
        const id = req.url.split("/")[2];
        getPostById(req,res,id);
    }
    else if (req.url == "/posts" && req.method == "POST") {
        createPost(req, res);
    }
    else if (req.url == "/posts" && req.method == "PUT") {
        updatePost(req, res);
    } else if (req.url == "/posts" && req.method == "DELETE") {
        deletePost(req, res);
    }
});

server.listen(4000, () => {
    console.log("Server up and running on port 4000")
})