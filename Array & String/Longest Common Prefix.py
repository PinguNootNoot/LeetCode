def longestCommonPrefix(strs):
    """
    :type strs: List[str]
    :rtype: str
    """
    maxPrefix = ''

    if len(strs) == 0:
        return maxPrefix

    target = ''
    source = strs[0]
    mismatch = False
    for i in range(len(source)):
        target += source[i]
        for j in range(len(strs)-1):
            if not strs[j+1].startswith(target):
                mismatch = True
            if mismatch:
                break

        if not mismatch:
            maxPrefix = target
        else:
            break

    return maxPrefix
