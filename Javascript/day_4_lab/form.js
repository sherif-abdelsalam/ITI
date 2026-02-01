var inpName = document.querySelector("#name");
var inpAge = document.querySelector("#age");
var inpEmail = document.querySelector("#email");

var users = [];
var tableBoy = document.querySelector('tbody');

function showError(input, message) {
    var span = input.nextElementSibling;
    span.textContent = message;
    span.style.display = "inline";
    input.classList.add("invalid");
}

function clearError(input) {
    var span = input.nextElementSibling;
    span.textContent = "";
    span.style.display = "none";
    input.classList.remove("invalid");
}

function validate() {
    var isValid = true;

    // Name
    if (inpName.value.trim() === "") {
        showError(inpName, "*This field is required");
        isValid = false;
    } else if (!isNaN(inpName.value)) {
        showError(inpName, "Name should be characters");
        isValid = false;
    } else {
        clearError(inpName);
    }

    // Age
    if (inpAge.value.trim() === "") {
        showError(inpAge, "*This field is required");
        isValid = false;
    } else if (isNaN(inpAge.value) || inpAge.value <= 0) {
        showError(inpAge, "Age must be greater than 0");
        isValid = false;
    } else {
        clearError(inpAge);
    }

    // Email
    if (inpEmail.value.trim() === "") {
        showError(inpEmail, "*This field is required");
        isValid = false;
    } else if (!/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/.test(inpEmail.value)) {
        showError(inpEmail, "Email is not valid");
        isValid = false;
    } else {
        clearError(inpEmail);
    }

    return isValid;
}

function renderTable() {
    if(users.length === 0) return;
    document.querySelector('table').style.display = "table";
    tableBoy.innerHTML = "";
    users.forEach(function(user, index) {
        var row = document.createElement("tr");
        row.innerHTML = "<td>" + user.name + "</td>\
                        <td>" + user.age + "</td>\
                        <td>" + user.email + "</td>";
        tableBoy.appendChild(row);
    });
}

document.querySelector("form").addEventListener("submit", function(e) {
    e.preventDefault();
    if(validate()) {
        users.push({
            name: inpName.value.trim(),
            age: Number(inpAge.value.trim()),
            email: inpEmail.value.trim()
        });
        renderTable();
        inpName.value = "";
        inpAge.value = "";
        inpEmail.value = "";
    }
});

document.querySelector('#reset').addEventListener("click", function() {
    users = [];
    tableBoy.innerHTML = "";
    document.querySelector('table').style.display = "none";
});