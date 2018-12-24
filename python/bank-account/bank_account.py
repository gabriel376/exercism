import threading

class BankAccount:
    def __init__(self):
        self.balance = 0;
        self.closed = True
        self.lock = threading.Lock()

    def open(self):
        if not self.closed:
            raise ValueError('account is already opened')
        self.closed = False

    def get_balance(self):
        if self.closed:
            raise ValueError('account is closed')
        return self.balance

    def deposit(self, amount):
        if self.closed:
            raise ValueError('account is closed')
        if amount < 1:
            raise ValueError('invalid amount')
        with self.lock:
            self.balance += amount

    def withdraw(self, amount):
        if self.closed:
            raise ValueError('account is closed')
        if self.balance < amount:
            raise ValueError('insufficient balance')
        if amount < 1:
            raise ValueError('invalid amount')
        with self.lock:
            self.balance -= amount

    def close(self):
        if self.closed:
            raise ValueError('account is already closed')
        self.closed = True
        self.balance = 0

