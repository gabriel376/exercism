ACTIONS = [
    'wink',
    'double blink',
    'close your eyes',
    'jump',
]

def handshake(code):
    actions = [action for index, action in enumerate(ACTIONS) if code & 2**index]
    if code & 2**len(ACTIONS):
        actions.reverse()
    return actions

def secret_code(actions):
    codes = [2**ACTIONS.index(action) for index, action in enumerate(actions) if action in ACTIONS]
    if codes != sorted(codes):
        codes += [2**len(ACTIONS)]
    return sum(codes)
