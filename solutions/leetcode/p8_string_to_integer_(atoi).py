class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()

        if s == "":
            return 0

        i = 0
        if s[0] == '+':
            sign = 1
            i = 1
        elif s[0] == '-':
            sign = -1
            i = 1
        else:
            sign = 1

        x = 0
        while i < len(s) and s[i].isdigit():
            x *= 10
            x += int(s[i])
            i += 1
        
        x *= sign

        if x < -2**31:
            x = -2**31
        elif x > 2**31 - 1:
            x = 2**31 - 1
        
        return x