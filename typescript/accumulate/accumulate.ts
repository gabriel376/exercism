function accumulate<T, U>(array: T[], pred: (_: T) => U): U[] {
    const result: U[] = [];
    for (const element of array) {
        const mapped: U = pred(element);
        result.push(mapped);
    }
    return result;
}

export default accumulate;
