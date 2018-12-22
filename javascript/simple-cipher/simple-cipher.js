const KEY_LEN = 100;
const CHAR_MIN = 'a';
const CHAR_MAX = 'z';

const Char = (c) => {
    return {
        str:  c,
        code: c.charCodeAt(0),
        add(x) {
            this.code = this.code + x;
            if (this.code > CODE_MAX)
                this.code = this.code - CODE_MAX + CODE_MIN - 1;
            if (this.code < CODE_MIN)
                this.code = this.code + CODE_MAX - CODE_MIN + 1;
            this.str = String.fromCharCode(this.code);
            return this;
        },
    };
}

const CODE_MIN = Char(CHAR_MIN).code;
const CODE_MAX = Char(CHAR_MAX).code;

const error = () => {
    throw new Error('Bad key');
};

const check = (key) => {
    Array.from(key)
        .forEach(k => {
            if (Char(k).code < CODE_MIN || Char(k).code > CODE_MAX)
                error();
        });
};

const random = () => {
    let rand = Math.random() * (CODE_MAX - CODE_MIN + 1);
    let code = Math.floor(rand) + CODE_MIN;
    return String.fromCharCode(code);
}

const generate = () => {
    let key = '';
    while (key.length < KEY_LEN) {
        key += random();
    }
    return key;
};

const transform = (key, str, mod) => {
    return Array.from(str)
        .map((x, i) => {
            let k = key[i % key.length];
            let diff = (Char(k).code - CODE_MIN) * mod;
            return Char(x).add(diff).str;
        })
        .join('');
};

export const Cipher = key => {
    if (key == '')
        error();
    else if (key)
        check(key);
    else
        key = generate();

    return {
        key: key,
        encode(str) {
            return transform(key, str, 1);
        },
        decode(str) {
            return transform(key, str, -1);
        },
    };
};
