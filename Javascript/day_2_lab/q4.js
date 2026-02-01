var sum = 0;
var mul = 1;
var numbers = [];
var div;

for (var i = 0; i < 3; i++) {
    do {
        var num = prompt("Enter number " + (i + 1) + ":");
    } while (!num || isNaN(num));

    numbers[i] = parseFloat(num); 
    sum += numbers[i];
    mul *= numbers[i];
    
    if (i === 0) {
        div = numbers[i]; 
    } else {
        div /= numbers[i]; 
    }
}

document.write("Sum of: " + numbers.join('+') + " = " + sum + "<br>");
document.write("Mul of: " + numbers.join('*') + " = " + mul + "<br>");
document.write("Div of: " + numbers.join('/') + " = " + div);
