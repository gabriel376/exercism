import re


class PhoneNumber:
    def __init__(self, phone):
        if re.match(r'.*[a-zA-Z]', phone):
            raise ValueError('letters not permitted')

        if re.match(r'.*[@:!]', phone):
            raise ValueError('punctuations not permitted')

        number = ''.join(filter(str.isdigit, phone))

        if len(number) == 11:
            if number[0] != '1':
                raise ValueError('11 digits must start with 1')
            number = number[1:]

        if len(number) < 10:
            raise ValueError('incorrect number of digits')

        if len(number) > 10:
            raise ValueError('more than 11 digits')

        area_code = number[:3]

        if area_code[0] == '0':
            raise ValueError('area code cannot start with zero')

        if area_code[0] == '1':
            raise ValueError('area code cannot start with one')

        exchange_code = number[3:6]

        if exchange_code[0] == '0':
            raise ValueError('exchange code cannot start with zero')

        if exchange_code[0] == '1':
            raise ValueError('exchange code cannot start with one')

        line_number = number[6:]

        self.number = number
        self.area_code = area_code
        self.exchange_code = exchange_code
        self.line_number = line_number

    def pretty(self):
        return f'({self.area_code})-{self.exchange_code}-{self.line_number}'
