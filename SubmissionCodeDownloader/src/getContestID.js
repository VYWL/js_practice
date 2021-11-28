const puppeteer = require('puppeteer');
const { ADMIN_ID, ADMIN_PW, JUDGE_DOMAIN } = require('./config');
const { getDataBySelector } = require('./utils');

async function getContestID() {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    const numberRegex = /[^0-9]/g;
    const textRegex = /[^A-Za-z-_0-9가-힣 ]/g;
    const loginPageURL = `${JUDGE_DOMAIN}/login`;

    await page.goto(loginPageURL);

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

    const contestListURL = `${JUDGE_DOMAIN}/jury/contests`;

    await page.goto(contestListURL);

    const contestTableBodySelector = `#DataTables_Table_0 > tbody > tr`;
    const totalContestCount = await page.$$eval(contestTableBodySelector, data => data.length);

    let nowIdx = 1;
    const contestIDList = [];
    while (nowIdx <= totalContestCount) {
        const rowSelector = contestTableBodySelector + `:nth-child(${nowIdx++}) > `;
        const contestIdSelector = rowSelector + `td:nth-child(1) > a`;
        const contestNameSelector = rowSelector + `td:nth-child(2) > a`;
        const contestDescriptionSelector = rowSelector + `td:nth-child(3) > a`;

        const contestID = await getDataBySelector(page, contestIdSelector, numberRegex);
        const contestName = (await getDataBySelector(page, contestNameSelector, textRegex)).trim();
        const contestDescription = (await getDataBySelector(page, contestDescriptionSelector, textRegex)).trim();

        contestIDList.push({ contestID, contestName, contestDescription, problemList: [] });
    }

    await browser.close();

    return contestIDList;
}

module.exports = getContestID;
