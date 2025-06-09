class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
         
class Solution(object):
    def partition(self, head, x):
         left , right = ListNode(), ListNode()
         ltail, rtail = left, right
         while head:
             if head.val < x:
                 ltail.next = head
                 ltail = ltail.next
             else:
                 rtail.next = head
                 rtail = rtail.next
             head = head.next
         ltail.next = right.next
         rtail.next = None
         return left.next

if __name__ == "__main__":
        # Example usage
        head = ListNode(1)
        head.next = ListNode(4)
        head.next.next = ListNode(3)
        head.next.next.next = ListNode(2)
        head.next.next.next.next = ListNode(5)
        head.next.next.next.next.next = ListNode(2)

        x = 3  # Partition around value 3

        solution = Solution()
        new_head = solution.partition(head, x)

        # Print the partitioned linked list
        current = new_head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")  # Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> None