class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def rotateRight(self, head, k):
         if not head:
                return head
         length, tail = 1, head
         while tail.next:
             tail = tail.next
             length += 1
         k %= length
         if k == 0:
            return head
         cur = head
         for i in range(length - k - 1):
             cur = cur.next
         newHead = cur.next
         cur.next = None
         tail.next = head
         return newHead
         
         

if __name__ == "__main__":
        # Example usage
        head = ListNode(1)
        head.next = ListNode(2)
        head.next.next = ListNode(3)
        head.next.next.next = ListNode(4)
        head.next.next.next.next = ListNode(5)

        k = 2  # Rotate the list to the right by 2 places

        solution = Solution()
        new_head = solution.rotateRight(head, k)

        # Print the rotated linked list
        current = new_head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")  # Output: 4 -> 5 -> 1 -> 2 -> 3 -> None