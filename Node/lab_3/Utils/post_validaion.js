
export const validatePost = (post) => {

    if (!post.title || post.title.trim().length === 0 
    || !post.content || post.content.trim().length === 0 ) {
        return false
    }
    return true
}