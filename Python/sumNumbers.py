
class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def sumNumbers(self, root):
        def dfs(cur, num):
            if not cur:
                return 0
            num = num * 10 + cur.val
            if not cur.left and not cur.right:
                return num
            return dfs (cur.left, num) + dfs(cur.right, num)
        return dfs(root, 0)
