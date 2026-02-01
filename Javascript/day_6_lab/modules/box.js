import { Book } from "./book.js";

export class Box {
    #height;
    #width;
    #length;
    #material;
    #content;
    #numOfBooks;

    constructor(height, width, length, material) {
        if (isNaN(height) || isNaN(width) || isNaN(length)
         || height <= 0 || width <= 0 || length <= 0
         || typeof material !== 'string' || material.trim() === ''
        ) {
            throw new Error("Not Valid Box, Enter a full valid info for the box.");
        }

        this.#height = +height;
        this.#width = +width;
        this.#length = +length;
        this.#material = material.trim();
        this.#content = [];
        this.#numOfBooks = 0;
    }


    get height() { return this.#height; }
    get width() { return this.#width; }
    get length() { return this.#length; }
    get material() { return this.#material; }
    get volume() { return this.#height * this.#width * this.#length; }
    get numOfBooks() { return this.#numOfBooks; }

    addBook(book) {
        if (!(book instanceof Book)) throw new Error("Only Book instances can be added");
        this.#numOfBooks += book.numOfCopies;
        this.#content.push(book);
    }

    deleteBookByTitle(title) {
        this.#content = this.#content.filter(book => {
            if (book.title === title) {
                this.#numOfBooks -= book.numOfCopies;
                return false;
            }
            return true;
        });
    }

    toString() {
        return `
Box Dimensions: ${this.#height} x ${this.#width} x ${this.#length}
Material: ${this.#material}
Volume: ${this.volume}
Number of Books: ${this.#numOfBooks}
Books:\n${this.#content.map((book, index) => ` ${index+1}) ` + book.toString()).join("\n")}
        `;
    }

    valueOf() {
        return this.#numOfBooks;
    }
}

