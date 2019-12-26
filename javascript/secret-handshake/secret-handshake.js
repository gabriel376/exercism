const ACTIONS = [
    'wink',
    'double blink',
    'close your eyes',
    'jump',
];

export const secretHandshake = (code) => {
    if (typeof code !== 'number')
        throw new TypeError('Handshake must be a number');

    const actions = ACTIONS.filter((_, i) => code & 1 << i);

    return code & 1 << ACTIONS.length
        ? actions.reverse()
        : actions;
};
