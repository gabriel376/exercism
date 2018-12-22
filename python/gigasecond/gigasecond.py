from datetime import timedelta

GIGASECOND = timedelta(seconds=1E9)

def add_gigasecond(moment):
    return moment + GIGASECOND
