function onlyTwoParamSum(x,y){
    if(arguments.length!==2){
        throw("arguments number should be 2");
    }
   return x+y;
}

console.log(onlyTwoParamSum(10,"20"));


function multiParamReverse() {
    return Array.from(arguments).reverse();
}

console.log(multiParamReverse(10, "20", "1", 4));


function sum(){
    var sumData = 0;
    for(var i=0;i<arguments.length;i++){
        var value = arguments[i];
        if (typeof value !== "number" || value!==NaN) {
            throw("all values should be numbers");
        }
        sumData+=arguments[i];
    }
    return sumData;

}
// console.log(sum());
// console.log(sum(30,60, NaN));



function dayName(date){
    var day = date.getDay();
    var dayNames = ["sunday","monday","tuesday","wednesday","thursday","friday","saturday"];
    return dayNames[day];
}

var dateNow = new Date();

console.log(dayName(dateNow));