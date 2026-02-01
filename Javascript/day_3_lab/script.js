// ** sorting question
// var numbers = [];
// var num;

// for (var i = 0; i < 5; i++) {
//     do {
//         num = prompt("Enter number " + (i + 1) + ":");
//     } while (!num || isNaN(num));
    
//     numbers[i] = Number(num);
// }

// var enteredNumbers = numbers.slice();
// var ascendingSorting = numbers.slice().sort(function (a, b) {
//     return a - b;
// });

// var descendingSorting = numbers.slice().sort(function (a, b) {
//     return b - a;
// });

// var p1 = document.createElement("p");
// p1.innerHTML = "<span style='color:red; font-weight:bold'>You have entered the values of: </span>" 
//                 + "<span>" + enteredNumbers.join(", ") + "</span>";
// document.body.append(p1);

// var p2 = document.createElement("p");
// p2.innerHTML = "<span style='color:red; font-weight:bold'>Ascending order: </span>" +
//                "<span>" + ascendingSorting.join(", ") + "</span>";
// document.body.append(p2);

// var p3 = document.createElement("p");
// p3.innerHTML = "<span style='color:red; font-weight:bold'>Descending order: </span>" +
//                "<span>" + descendingSorting.join(", ") + "</span>";
// document.body.append(p3);




// ** persons table question

var numberOfPersons;
do {
    numberOfPersons = prompt("Enter number of persons:");
} while (!numberOfPersons || isNaN(numberOfPersons) || numberOfPersons <= 0);

var persons = [];
for (var i = 0; i < numberOfPersons; i++) {
    var userName;
    do {
        userName = prompt("Enter name of person " + (i + 1) + ":");
    } while (!userName || !isNaN(userName) || userName.length<3 || userName.length>10); ;

    var age;
    do {
        age = prompt("Enter age of " + name + ":");
    } while (!age || isNaN(age) || age < 10 || age > 60); ;

    persons[i] = { name: userName, age: Number(age) };
}


var tableEl = document.querySelector("table");

var tbodyEle = document.createElement("tbody");

for (var i = 0; i < persons.length; i++) {
    var rowEle = document.createElement("tr");
    var nameCell = document.createElement("td");
    nameCell.style.width = "150px";
    nameCell.textContent = persons[i].name;

    var ageCell = document.createElement("td");
    ageCell.textContent = persons[i].age;

    rowEle.append(nameCell);
    rowEle.append(ageCell);

    tbodyEle.append(rowEle);
}

tableEl.append(tbodyEle);
tableEl.style.display = "table";