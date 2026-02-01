


// var y; 
// console.log(y); // undefined


// console.log(y); // Error: y is not defined

// var x = 10; 
// var y = 20; 
// console.log(y*x-2); // 198

// var y; 
// console.log(typeof y); // undefined

// var x = "1";
// var y = 2;
// console.log(x+y); // "12"

// var x = 1; 
// var y = true; 
// console.log(x+y); // 2




// q2


// do{
//     var msg = prompt("Enter a message: ");
// }while(!msg)

// for (var i = 1; i < 7; i++) {
//     document.write("<h"+i+">"+msg+"</h"+i+">");
// }




// // q3
// var sum = 0;
// var num;

// do {
//     num = prompt("Enter number or 0 to stop: ");
//     if (isFinite(num)) {
//         num = Number(num);
//         sum += num;
//     }
// } while (num != 0 && sum <= 100);

// alert("Total sum: " + sum);




// q4
// do{
//     var userName = prompt("Enter your name: ");
// }while(!userName || !isNaN(userName) );

// do{
//     var birthYear = prompt("Enter your birth year: ");
// }while(!birthYear || isNaN(birthYear) || birthYear >= 2010 );

// var age = 2026 - Number(birthYear);

// document.write("<u><b>Name: </b></u>" + userName + "<br>");
// document.write("<u><b>Birth year: </b></u>" + birthYear + "<br>");
// document.write("<u><b>Age: </b></u>" + age + "<br>");