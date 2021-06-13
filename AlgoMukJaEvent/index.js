import xlsx from "xlsx";

const totalTanNumber = 4;
const allResponseByTan = [];
const correctAnswerByTan = ["", 7, "안녕", "*오답", 15];
const nameDict = [];

// tanNumber는 중복제외를 위한 lastTan을 위해 넣었음.
const checkIn = (res_Name, isCorrect, tanNumber) => {
    const personObj = {
        name : res_Name,
        correctTan : isCorrect ? [tanNumber] : [],
        engagedTan : [tanNumber],
    }

    const personDataIndex = nameDict.findIndex(({name}) => name === res_Name);

    if(personDataIndex === -1) nameDict.push(personObj);
    else {
        const { name, correctTan, engagedTan } = nameDict[personDataIndex];

        // tan 중복 여기서
        if(engagedTan.find(prevTan => prevTan === tanNumber)) return;

        nameDict[personDataIndex] = {
            name,
            correctTan : isCorrect ? [...correctTan, tanNumber] : [...correctTan],
            engagedTan : [...engagedTan, tanNumber]
        }
    }

}

// 모든 응답을 처리
for(let tanNumber = 1; tanNumber <= totalTanNumber; tanNumber++) {
    const excelFile = xlsx.readFile(`./files/🍔 알고먹자 ${tanNumber}탄 🍗(응답).xlsx`);

    const sheetName = excelFile.SheetNames[0];
    const firstSheet = excelFile.Sheets[sheetName];       
    // @details 시트의 제목 추출
    // @details 엑셀 파일의 첫번째 시트를 읽어온다.

    const jsonData = xlsx.utils.sheet_to_json( firstSheet, { defval : "" } );

    // response별로 데이터 추출
    let correctCount = 0;
    const refinedData = jsonData.map((item) => {
        const isCorrect = item["🎈 정답은?"] === correctAnswerByTan[tanNumber];

        if(isCorrect) correctCount++;

        const timeStamp = item["타임스탬프"];
        const name = item["🙋‍♂️ 이름을 적어주세요! "];

        // 개인 별 참여횟수조사
        checkIn(name, isCorrect, tanNumber);

        return { timeStamp, name, isCorrect };
    })
    
    // 데이터 삽입
    allResponseByTan.push({
        tanNumber,
        correctCount,
        responses : refinedData
    });
};

// 1등 제출인데 틀린사람
const firstResponseButWA = allResponseByTan.map(item => {
    const { tanNumber : nowTan, responses : answer } = item;
    const { name, isCorrect } = answer[0];

    return isCorrect ? { nowTan, name } : null;
}).filter(item => item);

// 3번 틀린사람
// const threeWA = nameDict.map(({name, engagedTan, correctTan}) => {
//     const isThreeWA = 
//         (engagedTan.length === 3 && correctTan.length === 0) || 
//         (engagedTan.length === 4 && correctTan.length === 1)

//     if(isThreeWA) return name;
// }).filter(item => item);

// 3번 틀렸는데 3 & 4탄에서 못 받은 사람
const specialThreeWA = nameDict.map(({name, engagedTan, correctTan}) => {
    const isThreeWA = 
        (engagedTan.length === 3 && correctTan.length === 0) || 
        (engagedTan.length === 4 && correctTan.length === 1)

    const isSpecial = correctTan.find(item => item !== 3 || item !== 4) === undefined;

    if(isThreeWA && isSpecial) return name;
}).filter(item => item);

// 4번 시도했으나 한번도..
const allWA = nameDict.map(({name, engagedTan, correctTan}) => {
    const isAllWA = engagedTan.length === 4 && correctTan.length === 0;

    if(isAllWA) return name;
    else return;
}).filter(item => item);


console.log({
    '1등 제출인데 틀린사람' : firstResponseButWA,
    // '3번 틀린사람' : threeWA,
    '3번 틀렸는데 3 & 4탄에서 못 받은 사람' : specialThreeWA,
    '4번 시도했으나 한번도..' : allWA,
})

