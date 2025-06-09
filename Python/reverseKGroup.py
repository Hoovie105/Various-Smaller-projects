class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:
    def reverse(self, start, end):
        prev, curr = None, start
        while curr != end:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev

    def reverseKGroup(self, head, k):
        count, temp = 0, head
        while temp and count < k:
            temp = temp.next
            count += 1
        if count < k:
            return head

        new_head = self.reverse(head, temp)
        head.next = self.reverseKGroup(temp, k)
        return new_head

if __name__ == "__main__":
        # Example usage
        head = ListNode(1)
        head.next = ListNode(2)
        head.next.next = ListNode(3)
        head.next.next.next = ListNode(4)
        head.next.next.next.next = ListNode(5)

        k = 2  # Reverse every 2 nodes

        solution = Solution()
        new_head = solution.reverseKGroup(head, k)

        # Print the linked list after reversing in groups of k
        current = new_head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")  # Output: 2 -> 1 -> 4 -> 3 -> 5 -> None