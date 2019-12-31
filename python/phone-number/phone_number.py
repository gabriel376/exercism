class Phone:
    def __init__(self, phone):
        # extract only digits
        number = ''.join(filter(str.isdigit, phone))

        if len(number) == 11:
            # check country code
            if number[0] != '1':
                raise ValueError('Invalid Country Code')
            # remove country code
            number = number[1:]

        # check length
        if len(number) != 10:
            raise ValueError('Invalid Length')

        # check area code
        if number[0] in '01':
            raise ValueError('Invalid Area Code')

        # check exchange code
        if number[3] in '01':
            raise ValueError('Invalid Exchange Code')

        self.number        = number
        self.area_code     = number[:3]
        self.exchange_code = number[3:6]
        self.line_number   = number[6:]

    def pretty(self):
        return '({}) {}-{}'.format(
                self.area_code,
                self.exchange_code,
                self.line_number)
