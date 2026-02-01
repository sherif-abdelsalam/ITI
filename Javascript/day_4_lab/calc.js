var inp = document.querySelector("#Answer");
inp.readOnly = true;

function EnterNumber(num){
    inp.value += num;
}

var operators = ["+", "-", "*", "/"];

function EnterOperator(op){
    if(inp.value === ""){
        return;
    }
    var lastChar = inp.value[inp.value.length - 1];
    if(operators.includes(lastChar)){
        inp.value = inp.value.slice(0, -1) + op;
    } else {
        inp.value += op;
    }
}

function EnterEqual(){
    inp.value = eval(inp.value);
}

function EnterClear(){
    inp.value = "";
}