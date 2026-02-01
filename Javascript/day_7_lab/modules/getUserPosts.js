export async function GetUserPosts(user) {
    const res = await fetch( `https://jsonplaceholder.typicode.com/posts?userId=${user.id}`);
    const data = await res.json();

    const ul = document.getElementById("user-posts");
    ul.innerHTML="";

    data.forEach(post => {
        const li = document.createElement("li");
        li.textContent = post.title; 
        ul.appendChild(li);
    });

}
