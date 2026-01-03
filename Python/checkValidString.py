def checkValidString(s):
    low = 0  # Minimum number of open parentheses
    high = 0  # Maximum number of open parentheses

    for char in s:
        if char == '(':
            low += 1
            high += 1
        elif char == ')':
            low -= 1
            high -= 1
        else:  # char == '*'
            low -= 1  # Treat '*' as ')'
            high += 1  # Treat '*' as '('

        if high < 0:
            return False  # Too many closing parentheses

        if low < 0:
            low = 0  # We can't have negative open parentheses

    return low == 0  # Valid if we can have zero open parentheses at the end

if __name__ == "__main__":
    s = "(*))"
    assert checkValidString(s) == True