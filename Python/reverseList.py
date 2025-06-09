from hasCycle import ListNode

class Solution(object):
    def reverseList(self, head):
        prev = None
        current = head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev

if __name__ == "__main__":
    # Example usage
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    solution = Solution()
    reversed_head = solution.reverseList(head)

    # Print the reversed linked list
    current = reversed_head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")  # Output: 5 -> 4 -> 3 -> 2 -> 1 -> None
