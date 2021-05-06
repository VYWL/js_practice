import puppeteer from 'puppeteer';
import fs from 'fs';
import dotenv from 'dotenv';

dotenv.config({path: "../.env"});

(async () => {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();

    const user_id = process.env.USER_ID;
    const user_pw = process.env.USER_PW;
    const melonLoginURL = "https://member.melon.com/muid/web/login/login_inform.htm"

    await page.goto(melonLoginURL);

    console.log("멜론 로그인 페이지로 이동중...")

    await page.click('#conts_section > div > div > div:nth-child(3) > button');

    console.log("멜론 계정으로 로그인 페이지로 이동중...")

    await page.evaluate((id, pw) => {
        document.querySelector('#id').value = id;
        document.querySelector('#pwd').value = pw;
    }, user_id, user_pw);
    
    await page.click('#btnLogin');

    console.log("로그인 시도 중...")

    await page.waitForTimeout(1000);

    if(page.url() !== "https://www.melon.com/") {
        console.log("로그인 실패!")
        return;
    }

    console.log("로그인 성공!")
    console.log("내 플레이리스트 불러오는중...")

    await page.click("#gnb_menu > ul.sub_gnb > li > a > span.menu_bg.menu09");

    await page.waitForTimeout(700);
    
    await page.click('#conts > div.wrap_tab03.type09 > ul > li:nth-child(3) > a');
    
    await page.waitForTimeout(700);

    const totalNumberSelector = '#playlistList > div.wrab_list_info > div > span > span';
    const totalNumber = await page.$eval(totalNumberSelector, data => Number(data.textContent));

    console.log(`총 ${totalNumber}개의 플레이 리스트 발견!\n`)
    console.log("===========================\n")

    let songLists = [];
    let index = 1;
    while(index <= totalNumber) {
        const listTitleSelector = `#pageList > table > tbody > tr:nth-child(${index}) > td:nth-child(2) > div > div > dl > dt > a`;
        const listSizeSelector = `#pageList > table > tbody > tr:nth-child(${index}) > td.al_top > div > p`;
        const listGenreSelector = `#pageList > table > tbody > tr:nth-child(${index}) > td:nth-child(2) > div > div > dl > dd.themalk`
        
        const nowListTitle = await page.$eval(listTitleSelector, data => data.textContent);
        const nowListSize = await page.$eval(listSizeSelector, data => data.textContent);
        const nowListGenre = await page.$eval(listGenreSelector, data => String(data.textContent).replace("장르명", "").trim());
        
        songLists.push({
            id : index,
            spec : [ nowListTitle, nowListSize, nowListGenre].join('\n')
        })

        index++;
    }

    songLists.forEach(({spec}) => console.log(spec + '\n'));
    console.log("===========================\n")


    const selectedListIndex = 1;
    console.log(`${selectedListIndex}번 플레이리스트에 대해 작업 시작!\n`)

    await page.click(`#pageList > table > tbody > tr:nth-child(${selectedListIndex}) > td:nth-child(2) > div > div > dl > dt > a`);

    await page.waitForTimeout(700);
    
    const songCountSelector = '#songList > div > h3 > span'
    const songCount = await page.$eval(songCountSelector, data => Number(data.textContent.replace(/[^0-9]/g, "")))
    const playlistPageURL = `https://www.melon.com/mymusic/playlist/mymusicplaylistview_inform.htm?plylstSeq=492100349#params%5BplylstSeq%5D=492100349&po=pageObj&startIndex=`

    let nowSongIndex = 1;
    let totalSongList = [];
    while(nowSongIndex <= songCount) {
        const pageOffset = ((nowSongIndex - 1) / 50);
        const new_playlistPageURL = playlistPageURL + `${1 + pageOffset * 50}`;
    
        await page.goto(new_playlistPageURL);

        await page.waitForTimeout(700);
        
        for(let nowPageSongIndex = 1;nowPageSongIndex <= 50; nowPageSongIndex++) {
            if(nowSongIndex > songCount) break;
            
            const songTitleSelector = `#frm > div > table > tbody > tr:nth-child(${nowPageSongIndex}) > td:nth-child(3) > div > div > a.fc_gray`
            const songArtistSelector = `#frm > div > table > tbody > tr:nth-child(${nowPageSongIndex}) > td:nth-child(4) > div`
        
            const songTitle = await page.$eval(songTitleSelector, data => data.textContent);
            const songArtist = await page.$eval(songArtistSelector, data => String(data.textContent).trim().split("아티스트명 더보기")[0].trim());

            totalSongList.push({
                nowSongIndex,
                songTitle,
                songArtist
            })

            console.log(`총 ${songCount}개 중 ${nowSongIndex}개 완료`)
            nowSongIndex++;
        }

    }

    const targetPlaylistTitle = songLists[selectedListIndex-1].spec.split('\n')[0];
    fs.writeFileSync(`./myplaylist_${targetPlaylistTitle}.json`, JSON.stringify(totalSongList));

    console.log("(Ctrl + C로 종료하기)");

    await browser.close();
})();

