const puppeteer = require('puppeteer');
const getIDListWithProblemID = require('./getSubmissionIDList');
const dotenv = require('dotenv');

dotenv.config();
// 만약 src 폴더에서 직접 실행하는 경우 아래의 코드를 사용.
// dotenv.config({path: '../.env'});

async function downloadSourceFile (idList) {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    const admin_id = process.env.ADMIN_ID;
    const admin_pw = process.env.ADMIN_PASSWORD;
    const loginPageURL = 'http://waloha.kro.kr/login';

    await page.goto(loginPageURL);

    // Authentication :: put AdminID & AdminPassword
    await page.evaluate((id, pw) => {
    document.querySelector('input[name="_username"]').value = id;
    document.querySelector('input[name="_password"]').value = pw;
    }, admin_id, admin_pw);

    // Authentication :: Login Button Click
    await page.click('#loginform > div > form > button');

    if(page.url() === loginPageURL) {
        console.log("로그인 오류!")
        console.log(`아이디 : ${admin_id}`)
        console.log(`비밀번호 : ${admin_pw}`)
        return ;
    }


    let task = 0;
    while(task < idList.length) {
        const subID = idList[task];

        const sourceUrl = `http://waloha.kro.kr/jury/submissions/${subID}/source`
        await page.goto(sourceUrl);

        const client = await page.target().createCDPSession();
        await client.send('Page.setDownloadBehavior', {behavior: "allow", downloadPath: `./files/${subID}`})

        await page.click('#source-0 > div.mb-1 > a:nth-child(1)');

        await page.waitForTimeout(500);

        console.log(`총 ${idList.length} 중 ${task+1} 개 완료`)
        task++;
    }   

    await browser.close();    
};

(async () => {
    const problemID = 20;

    console.log(`문제번호 ${problemID}에 대한 제출 코드 추출`);

    // problem 번호를 파라미터 값으로 넣기
    const idList = await getIDListWithProblemID(problemID);
    
    // idList를 넣어서 파일로 저장
    await downloadSourceFile(idList);

    console.log("끝! (Ctrl + C 로 종료)");
})();