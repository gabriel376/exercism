export default class ArmstrongNumbers {
    static isArmstrongNumber(num: number): boolean {
        let str: string = String(num);
        let exp: number = str.length;
        let sum: number = Array.from(str)
            .map(Number)
            .reduce((acc, n) => acc + Math.pow(n, exp), 0);
        return sum == num;
    }
}
