module.exports = old => {
    let trans = {};
    Object.keys(old)
        .forEach(key => {
            old[key].forEach(letter => {
                trans[letter.toLowerCase()] = parseInt(key);
            });
        });
    return trans;
};
