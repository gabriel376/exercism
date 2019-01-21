export const isPangram = text => {
    let letters = text.toLowerCase().match(/[a-z]/g) || [];
    return new Set(letters).size == 26
}
