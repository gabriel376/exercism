module.exports = {
    toRoman: function(num) {
        let roman = {
            1000: 'M',
            900: 'CM',
            500: 'D',
            400: 'CD',
            100: 'C',
            90: 'XC',
            50: 'L',
            40: 'XL',
            10: 'X',
            9: 'IX',
            5: 'V',
            4: 'IV',
            1: 'I'
        };

        let keys = Object.keys(roman).reverse();
        let key = 0;
        let str = '';
        while (keys[key]) {
            if (num - keys[key] >= 0) {
                str += roman[keys[key]];
                num -= keys[key];
            } else {
                key++;
            }
        }

        return str;
    }
};
