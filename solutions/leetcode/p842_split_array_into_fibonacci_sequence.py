class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        MAX_N = 2**31
        n = len(num)
        curr = []

        def backtrack(i):
            if i==n:
                return True

            for j in range(i,n):
                str_n = num[i:j+1]
                m = int(str_n)
                if str_n[0]=='0' and m!=0: return False

                if m>curr[-1]+curr[-2]:
                    return False
                elif m==curr[-1]+curr[-2]:
                    curr.append(m)
                    flag = backtrack(j+1)
                    if flag: return curr
                    curr.pop()
                    break

            return False

        for i in range(n-2):
            str_n = num[0:i+1]
            m = int(str_n)
            if str_n[0]=='0' and m!=0: return []
            curr.append(m)

            for j in range(i+1,n-1):
                str_n = num[i+1:j+1]
                m = int(str_n)
                if str_n[0]=='0' and int(str_n)!=0: break

                curr.append(m)
                flag = backtrack(j+1)
                if flag and curr[-1]<MAX_N: return curr
                curr.pop()

            curr.pop()

        return []
    
# Just brute force with backtracking
# Need to cover edge case of leading zeros and num > 2**31 (MAX_INT)
# Used python because of its ability to handle large integers and string manipulation