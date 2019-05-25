type predicate<T> = (_: T) => boolean;

function keep<T>(array: T[], pred: predicate<T>): T[] {
    let result: T[] = [];
    for (let element of array) {
        if (pred(element)) {
            result.push(element);
        }
    }
    return result;
}

function discard<T>(array: T[], pred: predicate<T>): T[] {
    return keep(array, (el: T) => !pred(el));
}

export {
    keep,
    discard,
}
