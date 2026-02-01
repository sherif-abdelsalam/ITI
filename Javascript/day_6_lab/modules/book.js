export class Book {
    #title;
    #numOfChapters;
    #author;
    #numOfPages;
    #publisher;
    #numOfCopies;

    constructor(title, numOfChapters, author, numOfPages, publisher, numOfCopies) {
        if (typeof title !== 'string' || title.trim() === '' ||
            typeof author !== 'string' || author.trim() === '' ||
            typeof publisher !== 'string' || publisher.trim() === '' ||
            isNaN(numOfChapters) || numOfChapters <= 0 ||
            isNaN(numOfPages) || numOfPages <= 0 ||
            isNaN(numOfCopies) || numOfCopies <= 0
        ) {
            throw new Error("Not valid book info, Enter a full valid info for the book!!")
        }

        this.#title = title.trim();
        this.#numOfChapters = +numOfChapters;
        this.#author = author.trim();
        this.#numOfPages = +numOfPages;
        this.#publisher = publisher.trim();
        this.#numOfCopies = +numOfCopies;
    }

    get title() { return this.#title; }
    get author() { return this.#author; }
    get numOfCopies() { return this.#numOfCopies; }

    toString() {
        return `Title: ${this.#title}, Author: ${this.#author}, Pages: ${this.#numOfPages}, Chapters: ${this.#numOfChapters}, Publisher: ${this.#publisher}, Copies: ${this.#numOfCopies}`;
    }
}