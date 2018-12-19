export const steps = (num, count = 0) => {
    if (num < 1)
        throw new Error('Only positive numbers are allowed');

    if (num == 1)
        return count;

    num = num % 2 == 0
        ? num / 2
        : (num * 3) + 1;

    count += 1;
    
    return steps(num, count);
};
