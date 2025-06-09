from hasCycle import ListNode

class Solution(object):
    def addTwoNumbers(self, l1, l2):
          dummy = ListNode(0)
          current = dummy
          carry = 0

          while l1 or l2 or carry:
                v1 = l1.val if l1 else 0
                v2 = l2.val if l2 else 0
                total = v1 + v2 + carry
                carry = total // 10
                total %= 10
                current.next = ListNode(total)
                current = current.next
                if l1:
                    l1 = l1.next
                if l2:
                    l2 = l2.next

          return dummy.next

if __name__ == "__main__":
    # Example usage
    # Create first linked list: 2 -> 4 -> 3 (represents the number 342)
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    # Create second linked list: 5 -> 6 -> 4 (represents the number 465)
    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    solution = Solution()
    result = solution.addTwoNumbers(l1, l2)

    # Print the result linked list
    while result:
        print(result.val, end=" -> ")
        result = result.next
    print("None")  # Output: 7 -> 0 -> 8 -> None (represents the number 807)