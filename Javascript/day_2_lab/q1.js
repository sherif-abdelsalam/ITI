var regName = /^[A-Za-z]+$/;
var regPhoneNumber = /^[0-9]{8}$/;
var regMobileNumber = /^(010|011|012)[0-9]{8}$/;
var regEmail = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;

var userName, userPhone, userMobile, userEmail;

do {
    userName = prompt("Enter your name:");
} while (!userName || !regName.test(userName));

do {
    userPhone = prompt("Enter your phone number:");
} while (!userPhone || !regPhoneNumber.test(userPhone));

do {
    userMobile = prompt("Enter your mobile number:");
} while (!userMobile || !regMobileNumber.test(userMobile));

do {
    userEmail = prompt("Enter your email:");
} while (!userEmail || !regEmail.test(userEmail));
    
document.write("<h1>Welcome " + userName + "</h1>");
document.write("<p>Phone Number: " + userPhone + "</p>");
document.write("<p>Mobile Number: " + userMobile + "</p>");
document.write("<p>Email: " + userEmail + "</p>");