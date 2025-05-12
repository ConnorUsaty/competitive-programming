class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        cnt1 = [0] * 10
        for d in digits:
            cnt1[d] += 1
        
        ans = []
        for n in range(100,1000,2):
            cnt2 = [0] * 10
            for c in str(n):
                cnt2[int(c)] += 1
                
            if all(c1>=c2 for c1,c2 in zip(cnt1,cnt2)):
                ans.append(n)

        return ans

# constrained by 3 dig even numbers
# digits are only 0 to 9
# therefore can use this solution to meet constraints very efficiently technically giving O(1) time and space

# used .py instead of .cpp for easy str to int conv and all() func