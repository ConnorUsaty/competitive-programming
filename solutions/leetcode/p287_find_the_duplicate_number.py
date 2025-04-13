class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        while True:
            fast = nums[nums[fast]]
            slow = nums[slow]
            if slow == fast:
                break
        
        slow = nums[0]
        while slow != fast:
            fast = nums[fast]
            slow = nums[slow]
        
        return slow
    
# Uses Floyd's Tortoise and Hare algorithm to find the duplicate number in an array