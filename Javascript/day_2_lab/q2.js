var regName = /^[A-Za-z]+$/;
var str;

do {
    str = prompt("Enter your word:");
} while (!str || !regName.test(str));

var isCaseSen = confirm("Do you want to consider case sensitivity?");
if (!isCaseSen) {
    str = str.toLowerCase();
}

var reversedWord = str.split('').reverse().join('');

if (str === reversedWord) {
    alert("Palindrome");
} else {
    alert("Not palindrome");
}
