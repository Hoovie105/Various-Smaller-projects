class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        oldtocopy = {None: None}
        current = head
        while current:
            copy = Node(current.val)
            oldtocopy[current] = copy
            current = current.next
        current = head
        while current:
            copy = oldtocopy[current]
            copy.next = oldtocopy.get(current.next)
            copy.random = oldtocopy.get(current.random)
            current = current.next
        return oldtocopy[head]