export class List {
    constructor(values=[]) {
        this.values = values;
    }

    append(list) {
        for (const value of list) {
            this.push(value);
        }
        return this;
    }

    concat(list) {
        for (const value of list) {
            if (value instanceof List) {
                this.append(value);
            } else {
                this.push(value);
            }
        }
        return this;
    }

    filter(func) {
        const list = new List();
        for (const value of this) {
            if (func(value)) {
                list.push(value);
            }
        }
        return list;
    }

    map(func) {
        const list = new List();
        for (const value of this) {
            list.push(func(value));
        }
        return list;
    }

    length() {
        let count = 0;
        for (const value of this) {
            count += 1;
        }
        return count;
    }

    foldl(func, start) {
        let result = start;
        for (const value of this) {
            result = func(result, value);
        }
        return result;
    }

    foldr(func, start) {
        return this.reverse().foldl(func, start);
    }

    reverse() {
        const func = (list, value) => new List().push(value).concat(list);
        const start = new List();
        return this.foldl(func, start);
    }

    push(value) {
        this.set(this.length(), value);
        return this;
    }

    get(index) {
        return this.values[index];
    }

    set(index, value) {
        this.values[index] = value;
    }

    [Symbol.iterator]() {
        return this.values[Symbol.iterator]();
    }
}
