class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def isSameTree(self, p, q):
         if not p and not q:
             return True
         if not p or not q:
             return False
         if p.val != q.val:
             return False
         return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

if __name__ == "__main__":
        # Example usage
        p = TreeNode(1)
        p.left = TreeNode(2)
        p.right = TreeNode(3)

        q = TreeNode(1)
        q.left = TreeNode(2)
        q.right = TreeNode(3)

        solution = Solution()
        print(solution.isSameTree(p, q))  # Output: True

        q.right.val = 4
        print(solution.isSameTree(p, q))  # Output: False