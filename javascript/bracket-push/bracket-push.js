const DELIMITERS = "()[]{}";

export function bracketPush(input) {
    const stack = [];

    for (let c of input) {
        const index = DELIMITERS.indexOf(c);

        if (index < 0) {
            continue;
        }

        if (index % 2 === 0) {
            stack.push(index+1);
            continue;
        }

        if (stack.pop() !== index) {
            return false;
        }
    }

    return !stack.length;
}
