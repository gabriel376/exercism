class Luhn:
    def __init__(self, card):
        self.card = card

    def valid(self):
        total = 0
        count = 0

        for c in self.card[::-1]:
            if c == ' ':
                continue

            if not str.isdigit(c):
                return False

            digit = int(c)
            digit = 2*digit if count % 2 > 0 else digit
            digit = digit-9 if digit > 9 else digit

            total += digit
            count += 1

        return count > 1 and total % 10 == 0

