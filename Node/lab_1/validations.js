const validateId = (id) => {
    if (typeof id !== "number" || !Number.isInteger(id) || id <= 0) {
        return false;
    }
    return true;
}

const validateTitleContent = (val) => {
    if (typeof val !== "string" || val.trim().length === 0) {
        return false;
    }
    return true;
}

exports.validateId = validateId;
exports.validateTitleContent = validateTitleContent;

exports.validatePost = (post) => {
    if (
        post.id === undefined || !validateId(post.id) ||
        post.title === undefined || !validateTitleContent(post.title) ||
        post.content === undefined || !validateTitleContent(post.content)
    ) {
        return false;
    }
    return true;
}