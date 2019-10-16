export class WordProblem {
    constructor(question) {
        this.question = question;
    }

    answer() {
        const numbers = this.numbers();
        const operators = this.operators();

        if (!this.valid()
         || !numbers
         || !operators
         || numbers.length !== operators.length + 1) {
            throw new ArgumentError();
        }

        return operators.reduce((result, operator, index) => {
            switch (operator) {
                case 'plus':
                    return result + +numbers[index + 1];
                case 'minus':
                    return result - +numbers[index + 1];
                case 'multiplied by':
                    return result * +numbers[index + 1];
                case 'divided by':
                    return result / +numbers[index + 1];
            }
        }, +numbers[0]);
    }

    valid() {
        const regex = /^What is -?\d+( (plus|minus|multiplied by|divided by) -?\d+)+\?$/;
        return this.question.match(regex);
    }

    numbers() {
        const regex = /[-]{0,1}\d+/g;
        return this.question.match(regex);
    }

    operators() {
        const regex = /(plus|minus|divided by|multiplied by)+/g;
        return this.question.match(regex);
    }
}

export class ArgumentError {

}
