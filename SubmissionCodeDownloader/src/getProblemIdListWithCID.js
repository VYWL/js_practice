const puppeteer = require('puppeteer');
const { ADMIN_ID, ADMIN_PW, JUDGE_DOMAIN } = require('./config');
const { getDataBySelector } = require('./utils');

async function getProblemIdListWithCID(contestIdList) {
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

    // DEEP COPY :: for return List
    const contestData = [...contestIdList];

    let idx = 0;
    while (idx < contestData.length) {
        const { contestID } = contestData[idx];

        const contestSpecURL = `${JUDGE_DOMAIN}/jury/contests/${contestID}`;

        // Move to target URL
        await page.goto(contestSpecURL);

        await page.screenshot({ path: 'temp2.jpg' });

        const problemTableSelector = `body > div > div > div > div:nth-child(9) > div > table > tbody > tr`;
        const totalProblemCount = await page.$$eval(problemTableSelector, data => data.length);

        let nowIdx = 1;
        const problemList = [];
        while (nowIdx <= 1) {
            const rowSelector = problemTableSelector + `:nth-child(${nowIdx++}) > `;
            const problemIdSelector = rowSelector + `td:nth-child(1) > a`;
            const problemTitleSelector = rowSelector + `td:nth-child(2) > a`;
            const problemCodeSelector = rowSelector + `td:nth-child(3) > a`;

            const problemID = await getDataBySelector(page, problemIdSelector, numberRegex);
            const problemName = (await getDataBySelector(page, problemTitleSelector, textRegex)).trim();
            const problemCode = (await getDataBySelector(page, problemCodeSelector, textRegex)).trim();

            problemList.push({
                problemID,
                problemName,
                problemCode,
            });
        }

        contestData[idx]['problemList'] = problemList;
        idx++;
    }

    await browser.close();

    return contestData;
}

module.exports = getProblemIdListWithCID;
