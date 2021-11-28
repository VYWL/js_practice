const puppeteer = require('puppeteer');
const getIDListWithProblemID = require('./getSubmissionIDList');
const getProblemIdListWithCID = require('./getProblemIdListWithCID');
const { ADMIN_ID, ADMIN_PW, JUDGE_DOMAIN } = require('./config');
const getContestID = require('./getContestID');

async function downloadSourceFile(problemTitle, idList) {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
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

    let task = 0;
    while (task < idList.length) {
        const subID = idList[task];

        const sourceUrl = `${JUDGE_DOMAIN}/jury/submissions/${subID}/source`;
        await page.goto(sourceUrl);

        const client = await page.target().createCDPSession();
        await client.send('Page.setDownloadBehavior', {
            behavior: 'allow',
            downloadPath: `./files/${problemTitle}/${subID}`,
        });

        await page.click('#source-0 > div.mb-1 > a:nth-child(1)');

        await page.waitForTimeout(500);

        console.log(`총 ${idList.length} 중 ${task + 1} 개 완료`);
        task++;
    }

    await browser.close();
}

// TODO :: 매 Problem 처리할때마다 browser를 열고 닫음 => 최적화 필요.
(async () => {
    // 전체 Contest 정보를 제공 : idx를 선택
    const contestID = 20;
    const contestTitle = 'HCPC_ADV';
    const problemID = 91;
    const problemTitle = '그래프의 줄기';

    // 선택한 contest id를 갖는 contest의

    const contestIdList = await getContestID();

    console.log(`Contest 총 ${contestIdList.length}개 발견!`);

    const contestData = await getProblemIdListWithCID(contestIdList);

    // console.log(`${contestTitle}(${contestID}) : 문제번호 ${problemID}, \"${problemTitle}\"에 대한 제출 코드 추출`);

    // problem 번호를 파라미터 값으로 넣기
    // const idList = await getIDListWithProblemID(problemID);

    // idList를 넣어서 파일로 저장
    // await downloadSourceFile(problemTitle, idList);

    // idList를 로그 객체에 등록

    console.log('끝! (Ctrl + C 로 종료)');
})();
