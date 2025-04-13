# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow = head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True
        
        return False
        
# The above code uses Floyd's Cycle Detection Algorithm (Tortoise and Hare algorithm) to determine if a linked list has a cycle.
# If we want to find the node where the cycle begins we need to do a second pass after detecting the cycle
# We reset slow to the head and move both slow and fast one step at a time until they meet again.
# The node where they meet is the start of the cycle.
# The time complexity of this algorithm is O(n) and the space complexity is O(1).
