def longestValidParentheses(s):
    """
    :type s: str
    :rtype: int
    """
    if len(s) <= 1:
        return 0

    left = 0
    right = 0
    currentLen = 0
    maxLen = 0

    # Start from left
    for i in range(len(s)):
        if s[i] == '(':
            left += 1
        elif s[i] == ')':
            right += 1

        if left == right:
            currentLen = left + right

        elif left < right:
            if maxLen < currentLen:
                maxLen = currentLen

            left = 0
            right = 0
            currentLen = 0

    if maxLen < currentLen:
        maxLen = currentLen

    left = 0
    right = 0
    currentLen = 0
    i = len(s) - 1

    # Start from right
    while i >= 0:
        if s[i] == '(':
            left += 1
        elif s[i] == ')':
            right += 1

        if left == right:
            currentLen = left + right

        elif left > right:
            if maxLen < currentLen:
                maxLen = currentLen

            left = 0
            right = 0
            currentLen = 0
        i -= 1

    if maxLen < currentLen:
        maxLen = currentLen

    return maxLen
