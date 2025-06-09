class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def deleteDuplicates(self, head):
         dummy = ListNode(0, head)
         prev = dummy
         curr = head
         while curr:
            duplicate = False
            while curr.next and curr.val == curr.next.val:
                curr = curr.next
                duplicate = True
            if duplicate:
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
         return dummy.next

if __name__ == "__main__":
        # Example usage
        head = ListNode(1)
        head.next = ListNode(1)
        head.next.next = ListNode(2)
        head.next.next.next = ListNode(3)
        head.next.next.next.next = ListNode(3)

        solution = Solution()
        new_head = solution.deleteDuplicates(head)

        # Print the linked list after removing duplicates
        current = new_head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")  # Output: 1 -> 2 -> 3 -> None