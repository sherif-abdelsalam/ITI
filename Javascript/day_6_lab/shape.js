class Shape {
    static #count = 0;

    constructor() {
        if(this.constructor === Shape) {
            throw new Error("Abstract class 'Shape' cannot be instantiated directly.");
        }
        Shape.#count++;

    }
    static getCount() {
        return Shape.#count;
    }
    area() {
        throw new Error("Method 'area()' must be implemented.");
    }
    perimeter() {
        throw new Error("Method 'perimeter()' must be implemented.");
    }
}

class Rectangle extends Shape {
    
    static #isCreated = false;
    constructor(width, height) {
        if(Rectangle.#isCreated) {
            throw new Error("Only one instance of 'Rectangle' is allowed.");
        }
        super();    
        this.width = width;
        this.height = height;
        Rectangle.#isCreated = true;
    }
    area() {
        return this.width * this.height;
    }
    perimeter() {
        return 2 * (this.width + this.height);
    }
    toString() {
        return `Rectangle - Area: ${this.area()}, Perimeter: ${this.perimeter()}`;
    }
}

class Square extends Shape {

    static isCreated = false;

    constructor(side) {
        if (Square.isCreated) {
            throw new Error("Only one instance of 'Square' is allowed.");
        }
        Square.isCreated = true;
        super();
        this.side = side;
    }

    area() {
        return this.side * this.side;
    }

    perimeter() {
        return 4 * this.side;
    }

    toString() {
        return `Square - Area: ${this.area()}, Perimeter: ${this.perimeter()}`;
    }
}


class Circle extends Shape {
    constructor(radius) {
        super();
        this.radius = radius;
    }
    area() {
        return Math.PI * this.radius * this.radius;
    }
    perimeter() {
        return 2 * Math.PI * this.radius;
    }   
    toString() {
        return `Circle - Area: ${this.area()}, Perimeter: ${this.perimeter()}`;
    }   
}

const rect = new Rectangle(4, 5);
// const rect2 = new Rectangle(6, 7); 
const square = new Square(4);
// const square2 = new Square(9);
const circle = new Circle(3);
const circle2 = new Circle(3);



console.log(rect.toString());
console.log(square.toString());
console.log(circle.toString());
console.log(`Total Shapes Created: ${Shape.getCount()}`);