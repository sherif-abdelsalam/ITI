
let fruits = ["apple", "strawberry", "banana", "orange", "mango"];

let isEveryElementString = fruits.every(e=> typeof e === "string");
let isSomeElementStartsWith_a = fruits.some(e => e.startsWith("a"));
let filteredFruites = fruits.filter(e=> e.startsWith("b") || e.startsWith("s"));
let newFruitsArr = fruits.map(e => `I like ${e}`);


console.log(fruits);
console.log(isEveryElementString);
console.log(isSomeElementStartsWith_a);
console.log(filteredFruites);
console.log(newFruitsArr);