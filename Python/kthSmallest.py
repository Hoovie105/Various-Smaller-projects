class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def kthSmallest(self, root, k):
        res = []
        def dfs(node, k):
            if not node:
                return
            dfs(node.left, k)
            res.append(node.val)
            dfs(node.right, k)
        dfs(root, k)
        return res [k - 1]
