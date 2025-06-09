class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def removeNthFromEnd(self, head, n):
         dummy = ListNode(0, head)
         left = dummy
         right = head
         while n > 0 and right:
              right = right.next
              n -= 1
         while right:
              left = left.next
              right = right.next
         left.next = left.next.next
         return dummy.next

if __name__ == "__main__":
        # Example usage
        head = ListNode(1)
        head.next = ListNode(2)
        head.next.next = ListNode(3)
        head.next.next.next = ListNode(4)
        head.next.next.next.next = ListNode(5)

        n = 2  # Remove the 2nd node from the end (should remove node with value 4)

        solution = Solution()
        new_head = solution.removeNthFromEnd(head, n)

        # Print the modified linked list
        current = new_head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")  # Output: 1 -> 2 -> 3 -> 5 -> None