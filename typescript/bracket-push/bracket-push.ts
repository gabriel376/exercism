const DELIMITERS: string = "()[]{}";

export default class BracketPush {
    constructor(private input: Readonly<string>) {

    }

    isPaired(): boolean {
        const stack: number[] = [];

        for (let c of this.input) {
            const index: number = DELIMITERS.indexOf(c);

            if (index < 0) {
                continue;
            }

            if (index % 2 === 0) {
                stack.push(index+1);
                continue;
            }

            if (index !== stack.pop()) {
                return false;
            }
        }

        return !stack.length;
    }
}
