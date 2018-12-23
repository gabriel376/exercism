class ReverseString {
    static reverse(str: string): string {
        return Array.from(str)
            .reverse()
            .join('');
    }
}

export default ReverseString
