class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def isValidBST(self, root):
        def dfs(root, left, right):
            if not root:
                return True
            if not (root.val < right and root.val > left):
                return False
            return (dfs(root.left, left, root.val) and 
             dfs(root.right, root.val, right))
        
        return dfs(root, float("-inf"), float("inf"))
            
            