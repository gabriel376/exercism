BRACKETS = '()[]{}'

def is_paired(string):
    string = [char for char in string if char in BRACKETS]
    stack = []

    for char in string:
        index = BRACKETS.index(char)

        if index % 2 == 0:
            stack.append(index+1)

        elif not stack or stack.pop() != index:
            return False

    return not stack
