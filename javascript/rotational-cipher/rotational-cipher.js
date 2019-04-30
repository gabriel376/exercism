function rotate(char, shift) {
    if (!char.match(/[a-z]/i)) {
        return char;
    }

    const code = char.charCodeAt() + shift;
    const base = (char.match(/[a-z]/) ? 'a' : 'A').charCodeAt();
    const limit = (char.match(/[a-z]/) ? 'z' : 'Z').charCodeAt();

    if (code <= limit) {
        return String.fromCharCode(code);
    }

    return String.fromCharCode(code + base - limit - 1);
}

export class RotationalCipher {
    static rotate(string, shift) {
        return [...string].map(char => rotate(char, shift)).join('');
    }
}
