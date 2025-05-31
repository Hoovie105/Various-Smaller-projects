# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        tail = dummy
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        if list1:
            tail.next = list1
        elif list2:
            tail.next = list2
        return dummy.next

if __name__ == "__main__":
    # Example usage
    list1 = ListNode(1, ListNode(2, ListNode(4)))
    list2 = ListNode(1, ListNode(3, ListNode(4)))
    solution = Solution()
    merged_list = solution.mergeTwoLists(list1, list2)
    
    # Print merged list
    current = merged_list
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")  # Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> None
        