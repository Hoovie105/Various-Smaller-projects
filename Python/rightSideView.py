import collections
class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def rightSideView(self, root):
        res = []
        q = collections.deque([root])
        while q:
            right = None
            qlen = len(q)
            for i in range(qlen):
                node = q.popleft()
                if node:
                    right = node
                    q.append(node.left)
                    q.append(node.right)
            if right:
                res.append(right.val)
        return res

