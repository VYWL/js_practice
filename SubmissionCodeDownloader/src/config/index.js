const dotenv = require('dotenv');

dotenv.config();
// 만약 src 폴더에서 직접 실행하는 경우 아래의 코드를 사용.
// dotenv.config({path: '../.env'});

module.exports = {
    ADMIN_PW: process.env.ADMIN_PW,
    ADMIN_ID: process.env.ADMIN_ID,
    JUDGE_DOMAIN: process.env.OJ_DOMAIN,
};
