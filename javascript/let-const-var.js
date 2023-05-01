
//var 의 문제점
//중복 선언 가능 문제

var name = 'narme'; 
console.log(name);	//narme

var name = 'narmeee'
console.log(name);	//narmeee


//선언 전 참조 가능

console.log(name2);
var name2 = 'narme';

//function-level-scope

var name3 = 'narme';
console.log(name3);	//narme

{
    var name3;
    console.log(name3);	//narme
}
console.log(name3);	//narme

function myName(){
    var name3;
    console.log(name3);
}

myName();	//undefined


//let const 중복 선언 불가능

let letname = 'narme';
console.log(letname);

//let letname = 'narmeee'; //SyntaxError: Identifier 'letname' has already been declared

letname = 'narmeee';
console.log(letname);

//const let 차이점 : const는 선언과 초기화를 함께 해줘야하며 재할당이 불가능하다.

//const constname; //SyntaxError: Missing initializer in const declaration
const constname = 'narme';
//constname = 'narmeee'; //TypeError: Assignment to constant variable.



//객체 맴버는 가능
const objectname = {name : 'narme',};

objectname.name = 'narmeee';

// let const 선언 전 참조 가능

//console.log(declareconst); //ReferenceError: Cannot access 'declareconst' before initialization
const declareconst = 1;

//console.log(declarelet); //ReferenceError: Cannot access 'declarelet' before initialization
let declarelet = 1;


// let const 블록 스코프

let blocklet = 1;
const blockconst = 3;
{
    let blocklet = 2;
    console.log(blocklet);
    const blockconst = 4;
    
    console.log(blockconst);
}
console.log(blocklet);
console.log(blockconst);