const validate = validations => {
    validations.forEach(v => {
        if (v.checks.includes(true))
            throw new Error(v.message);
    });
};

const toBase10 = (digits, fromBase) => {
    return digits.reverse()
        .reduce((acc, cur, idx) => {
            return acc + (cur * Math.pow(fromBase, idx));
        }, 0);
};

const toBaseX = (valueBase10, toBase, result = []) => {
    result.unshift(valueBase10 % toBase);
    valueBase10 = Math.floor(valueBase10 / toBase);
    return valueBase10 == 0
        ? result
        : toBaseX(valueBase10, toBase, result);
};

export const convert = (digits, fromBase, toBase) => {
    let validations = [{
        message: 'Wrong input base',
        checks: [
            !fromBase,
            fromBase < 2,
            fromBase !== parseInt(fromBase),
        ],
    }, {
        message: 'Wrong output base',
        checks: [
            !toBase,
            toBase < 2,
            toBase !== parseInt(toBase),
        ],
    }, {
        message: 'Input has wrong format',
        checks: [
            digits.length == 0,
            digits.length > 1 && digits.join('').startsWith("0"),
            digits.some(x => x < 0 || x >= fromBase),
        ],
    }];

    validate(validations);

    let base10 = toBase10(digits, fromBase);
    let result = toBaseX(base10, toBase);

    return result;
};
