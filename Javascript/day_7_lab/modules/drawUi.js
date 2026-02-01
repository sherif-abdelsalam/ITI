import { GetUserPosts } from "./getUserPosts.js";

export function DrawUi(users) {
    const container = document.getElementById("users-div");
    users.forEach(user => {
        const btn = document.createElement("button");
        btn.className = "user-btn";
        btn.textContent = user.name;
        btn.addEventListener("click", () => {
            GetUserPosts(user);
        });

        container.appendChild(btn);
    });
}
