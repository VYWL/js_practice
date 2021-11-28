const puppeteer = require('puppeteer');
const { ADMIN_ID, ADMIN_PW, JUDGE_DOMAIN } = require('./config');

async function getIDListWithProblemID(problemID) {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    const idList = [];
    const regex = /[^0-9]/g;
    const problemSpecURL = `${JUDGE_DOMAIN}/jury/problems/${problemID}`;

    await page.goto(`${JUDGE_DOMAIN}/login`);

    // Authentication :: put AdminID & AdminPassword
    await page.evaluate(
        (id, pw) => {
            document.querySelector('input[name="_username"]').value = id;
            document.querySelector('input[name="_password"]').value = pw;
        },
        ADMIN_ID,
        ADMIN_PW
    );

    // Authentication :: Login Button Click
    await page.click('#loginform > div > form > button');

    if (page.url() === loginPageURL) {
        console.log('로그인 오류!');
        console.log(`아이디 : ${ADMIN_ID}`);
        console.log(`비밀번호 : ${ADMIN_PW}`);
        console.log(`* 환경변수 파일을 확인해주세요!`);
        return;
    }

    // Move to target URL
    await page.goto(problemSpecURL);

    const frameSelector = 'body > div > div > div > div:nth-child(10) > table > tbody > tr';
    const totalSubmission = await page.$$eval(frameSelector, data => data.length);

    let nowIdx = 1;
    while (nowIdx <= totalSubmission) {
        let temp = `:nth-child(${nowIdx++}) > td:nth-child(1) > a`;
        const rowSelector = frameSelector + temp;

        const submissionFrame = await page.$eval(rowSelector, data => String(data.textContent));
        idList.push(submissionFrame.replace(regex, ''));
    }

    await browser.close();

    return idList;
}

module.exports = getIDListWithProblemID;
