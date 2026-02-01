import { Box } from "./modules/box.js"
import { Book } from "./modules/book.js";

const book1 = new Book("JS", 8, "JSJS", 300, "pup", 90);
const book2 = new Book("HTML", 3, "HTCS", 120, "pup", 20);
const book3 = new Book("CSS", 4, "HTCS", 150, "pup", 35);

// console.log("Show book 1 info:")
// console.log(book1.toString());


const box1 = new Box(10, 5, 4, "Wood");
box1.addBook(book1);
box1.addBook(book2);
box1.addBook(book3);
// console.log("Show Box 1 Info: ");
// console.log(box1.toString());

// console.log("\nTotal books in box1:", box1.numOfBooks);  // 90 + 20 + 35
const box2 = box1;
console.log("\nTotal books in box1+box2:", box1+box2);  

box1.deleteBookByTitle("CSS");
console.log("Total books in box1 after deleing book 3: ", box1.numOfBooks); // 90 + 20

