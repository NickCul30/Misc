

def isPalindrome(x):

    digits = []

    while x > 0:
        digits.append(x % 10)
        x /= 10

    for i in range(0,len(digits) / 2):
        if digits[i] != digits[len(digits) - i - 1]:
            return False

    return True

print isPalindrome(122)
