export const hey = (message) => {
    const silence = !message.trim();
    const question = message.trim().endsWith('?');
    const shout = message.toUpperCase() === message
                  && message.match(/[A-Z]/);

    if (silence) {
        return 'Fine. Be that way!';
    }

    if (question && shout) {
        return 'Calm down, I know what I\'m doing!';
    }

    if (question) {
        return 'Sure.';
    }

    if (shout) {
        return 'Whoa, chill out!';
    }

    return 'Whatever.';
};
