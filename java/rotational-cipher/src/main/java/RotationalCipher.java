class RotationalCipher {

    private int shift;

    RotationalCipher(int shift) {
        this.shift = Math.abs(shift % 26);
    }

    public String rotate(String data) {
        return data.codePoints()
            .mapToObj(this::rotate)
            .collect(StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append)
            .toString();
    }

    private int rotate(int code) {
        if (isLetter(code)) {
            char base = Character.isUpperCase(code) ? 'A' : 'a';
            return ((code - base + shift) % 26) + base;
        }

        return code;
    }

    private boolean isLetter(int code) {
        return (code >= 'a' && code <= 'z')
            || (code >= 'A' && code <= 'Z');
    }
}
