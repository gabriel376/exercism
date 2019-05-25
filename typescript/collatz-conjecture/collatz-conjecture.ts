export default class CollatzConjecture {
    static steps(max: number): number {
        if (max <= 0) throw new Error('Only positive numbers are allowed');
        if (max == 1) return 0;
        if (max % 2)  return CollatzConjecture.steps(3 * max + 1) + 1;
        return CollatzConjecture.steps(max / 2) + 1;        
    }
}
