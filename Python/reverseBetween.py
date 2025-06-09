from hasCycle import ListNode

class Solution(object):
    def reverseBetween(self, head, left, right):
         dummy = ListNode(0, head)
         leftPrev, current = dummy, head

         for i in range(left - 1):
             leftPrev, current = current, current.next

         prev = None
         for i in range(right - left + 1):  # Fix: reverse correct number of nodes
              tmpNext = current.next
              current.next = prev
              prev, current = current, tmpNext
        
         leftPrev.next.next = current
         leftPrev.next = prev
         return dummy.next