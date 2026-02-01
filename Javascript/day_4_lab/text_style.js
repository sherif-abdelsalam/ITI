 var para = document.getElementById("PAR");

function ChangeFont(x){
    console.log(x);
    para.style.fontFamily = x;

}
function ChangeAlign(y){
    para.style.textAlign = y;
}

function ChangeHeight(lineHeight){
    para.style.lineHeight = lineHeight;
}


function ChangeLSpace(letterSpacing){
    para.style.letterSpacing = letterSpacing;
}

function ChangeIndent(textIndent){
    para.style.textIndent = textIndent;
}
function ChangeTransform(textTransform){
    para.style.textTransform = textTransform;
}
function ChangeDecorate(textDecorate){
    para.style.textDecoration = textDecorate;
}
function ChangeBorder(borderStyle){
    para.style.border = borderStyle;
}
function ChangeBorderColor(borderColor){
    para.style.borderColor = borderColor;
}
