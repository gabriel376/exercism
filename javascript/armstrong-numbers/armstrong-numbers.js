export const validate = number => {
    let str = String(number);
    let exp = str.length;
    let total =  Array.from(str)
        .reduce((acc, cur) => acc + Math.pow(cur, exp), 0);
    return number == total;
};
