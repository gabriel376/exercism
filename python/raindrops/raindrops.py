def raindrops(number):
    drops = {
        3: 'Pling',
        5: 'Plang',
        7: 'Plong',
    }

    sound = [drops[n] for n in drops if number % n == 0]

    return ''.join(sound) or str(number)
