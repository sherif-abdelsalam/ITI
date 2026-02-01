var radius;

do {
    radius = prompt("Enter circle radius:");
} while (!radius || isNaN(radius) || radius <= 0);

radius = Number(radius);
alert("Circle area: " + Math.PI * radius * radius);

var calcSquareRoot;
do {
    calcSquareRoot = prompt("Enter a number to calculate its square root:");
} while (!calcSquareRoot || isNaN(calcSquareRoot) || calcSquareRoot < 0);

calcSquareRoot = Number(calcSquareRoot);
alert("Square root: " + Math.sqrt(calcSquareRoot));