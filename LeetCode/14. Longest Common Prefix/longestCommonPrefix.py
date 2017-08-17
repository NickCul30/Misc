
def longestCommonPrefix(strs):

    """
    :type strs: List[str]
    :rtype: str
    """

    if len(strs) == 0:
        return ""

    pref = strs[0]

    for i in range(1, len(strs)):
        tmp = ""
        for j in range(0, min(len(pref), len(strs[i]))):
            if pref[j] == strs[i][j]:
                tmp = tmp + pref[j]
            else:
                pref = tmp
                break
        pref = tmp

    return pref

print longestCommonPrefix(["str","str1","st","hi"])
