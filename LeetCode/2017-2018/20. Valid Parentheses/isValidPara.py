
def isValidPara(s):
    """
    :type s: str
    :rtype: bool
    """
    
    leftBrac = ['(','[','{']
    rightBrac = [')',']','}']
    i = 0

    if len(s) < 2 or len(s) % 2 == 1: return  False

    while len(s) > 1 and i < len(s) - 1:
        i += 1
        for j in range(0,3):
            if s[i] == rightBrac[j]:
                if s[i-1] == leftBrac[j]:
                    s = s[:(i-1)] + s[(i+1):]
                    i -= 2
                    break
                else: return False

    if s == "": return True
    return False
            


print isValidPara("((")
