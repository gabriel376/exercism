export class Flattener {
    flatten(array) {
        const result = [];

        for (let element of array) {
            if (element == null) {
                continue;

            } else if (Array.isArray(element)) {
                for (let subelement of this.flatten(element)) {
                    result.push(subelement);
                }

            } else {
                result.push(element);
            }
        }

        return result;
    }
}
