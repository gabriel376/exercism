export const encode = str => {
    let count = 1;
    return Array.from(str).reduce((acc, cur, idx, arr) => {
        if (cur == arr[idx + 1]) {
            count++;
            return acc;
        }
        if (count > 1) {
            acc += count;
        }
        count = 1;
        return acc + cur;
    }, '');
};

export const decode = str => {
    let count = '';
    return Array.from(str).reduce((acc, cur, idx, arr) => {
        if (isNaN(cur) || cur == ' ') {
            if (count) {
                acc += cur.repeat(parseInt(count) - 1);
                count = '';
            }
            acc += cur;
            return acc;
        }
        count += cur;
        return acc;
    }, '');
}
