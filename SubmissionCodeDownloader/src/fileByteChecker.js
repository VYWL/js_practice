const fs = require('fs');

const dir = './files/';
const list =  fs.readdirSync(dir,"utf8");

// 코드길이 조사
const subList = list.map(elem => {
    const sourceDir = dir + elem
    const sourceFile = fs.readdirSync(sourceDir, "utf8");
    const sourceFileDir = sourceDir + `/${sourceFile[0]}`;

    const codeLength = fs.readFileSync(sourceFileDir, "utf8").length;

    return { subID : elem, length : codeLength};
})

// 피보나치 배열 준비
let fibo = [];
fibo.push(0);
fibo.push(1);
fibo.push(1);

for(let i = 3;i < 90; i++) {
    const nowValue = fibo[i-1] + fibo[i-2];

    fibo.push(nowValue);
}

// 검증
subList.forEach(elem => {
    const {subID, length} = elem;
    const isFibo = fibo.some(elem => elem === length);

    if(isFibo) console.log(`제출번호 ${subID}가 조건에 만족 => 길이 : ${length}`)
})
