class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        n = len(arr)
        ans = []

        while n>0:
            j = arr.index(n)
            
            ans.append(j+1)
            ans.append(n)
            for i in range((j+1)//2):
                arr[i], arr[j-i] = arr[j-i], arr[i]
            for i in range(n//2):
                arr[i], arr[n-1-i] = arr[n-1-i], arr[i]
            
            n -= 1
        
        return ans

        
# we can guarentee sort one element every two moves by putting max unsorted to [0] then flipping the entire unsorted portion
# therefore find index of max, flip until and including that index, then flip entire unsorted portion
# repeat until no unsorted portion