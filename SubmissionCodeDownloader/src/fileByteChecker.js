const fs = require('fs');

const dir = './files/';
const list = fs.readdirSync(dir, 'utf8');

// 코드길이 조사 : 보통 라인 끝에 white space 한칸씩 있어서 실제 코드양 + 라인수로 처리될거임.
const subList = list.map(elem => {
    const sourceDir = dir + elem;
    const sourceFile = fs.readdirSync(sourceDir, 'utf8');
    const sourceFileDir = sourceDir + `/${sourceFile[0]}`;

    const codeLength = fs.readFileSync(sourceFileDir, 'utf8').length;

    return { subID: elem, length: codeLength };
});

// // 피보나치 배열 준비
// let fibo = [];
// fibo.push(0);
// fibo.push(1);
// fibo.push(1);

// for(let i = 3;i < 90; i++) {
//     const nowValue = fibo[i-1] + fibo[i-2];

//     fibo.push(nowValue);
// }

let maxSID = 0,
    maxLength = -1;

// 검증
subList.forEach(elem => {
    const { subID, length } = elem;
    // const isFibo = fibo.some(elem => elem === length);

    if (maxLength < length) {
        maxSID = subID;
        maxLength = length;
    } else if (maxLength === length) {
    }
    // if(isFibo) console.log(`제출번호 ${subID}가 조건에 만족 => 길이 : ${length}`)
});

console.log(`최장길이 코드 subID : ${maxSID}, length : ${maxLength}`);

subResult = subList.sort((a, b) => b.length - a.length);

console.log(subResult);
