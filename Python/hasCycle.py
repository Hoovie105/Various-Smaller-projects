class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def hasCycle(self, head):
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next          # Move slow pointer by 1 step
            fast = fast.next.next     # Move fast pointer by 2 steps
            if slow == fast:
                return True
        return False
            
        

if __name__ == "__main__":
    # Example usage
    # Create a linked list with a cycle for testing
    head = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(-4)
    head.next.next.next.next = head.next  # Create a cycle

    solution = Solution()
    result = solution.hasCycle(head)
    print(result)  # Output: True (since there is a cycle in the linked list)