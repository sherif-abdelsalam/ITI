
export const validateInt = (val) => {
    return !isNaN(val) && val > 0;
}

    
export const validateString = (val) => {
    return typeof val === "string" && val.length > 0;
}


export const validateComment = (comment) => {
    if (!validateString(comment.author) || !validateString(comment.body)) {
        return false;
    }
    return true;
}