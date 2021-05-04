const puppeteer = require('puppeteer');
const dotenv = require('dotenv');

dotenv.config();
// 만약 src 폴더에서 직접 실행하는 경우 아래의 코드를 사용.
// dotenv.config({path: '../.env'});

async function getIDListWithProblemID (problemID) {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    const idList = [];
    const regex = /[^0-9]/g;
    const admin_id = process.env.ADMIN_ID;
    const admin_pw = process.env.ADMIN_PASSWORD;
    const problemSpecURL = `http://waloha.kro.kr/jury/problems/${problemID}`;

    await page.goto('http://waloha.kro.kr/login');

    // Authentication :: put AdminID & AdminPassword
    await page.evaluate((id, pw) => {
    document.querySelector('input[name="_username"]').value = id;
    document.querySelector('input[name="_password"]').value = pw;
    }, admin_id, admin_pw);

    // Authentication :: Login Button Click
    await page.click('#loginform > div > form > button');


    // Move to target URL
    await page.goto(problemSpecURL);

    const frameSelector = "body > div > div > div > div:nth-child(10) > table > tbody > tr";
    const totalSubmission = await page.$$eval(frameSelector, data => data.length);

    let nowIdx = 1;
    while(nowIdx <= totalSubmission) {
        let temp = `:nth-child(${nowIdx++}) > td:nth-child(1) > a`;
        const rowSelector = frameSelector + temp;

        const submissionFrame = await page.$eval(rowSelector,(data) => String(data.textContent));
        idList.push(submissionFrame.replace(regex, ''));
    }


    return idList;
}

module.exports = getIDListWithProblemID;