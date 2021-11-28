module.exports = {
    getDataBySelector: async (page, selector, regex = /[^0-9]/g) => {
        return (await page.$eval(selector, data => String(data.textContent))).replace(regex, '');
    },
};
