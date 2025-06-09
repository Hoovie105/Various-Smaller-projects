class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def flatten(self, root):
        def dfs(root):
            if not root:
                return None
            leftTail = dfs(root.left)
            rightTail = dfs(root.right)
            if leftTail:
                leftTail.right = root.right
                root.right = root.left
                root.left = None
            last = rightTail or leftTail or root
            return last
        dfs(root)
