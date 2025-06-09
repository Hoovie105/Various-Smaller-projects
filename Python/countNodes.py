class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def countNodes(self, root):
          if not root:
              return 0
          def Lheight(node):
              if not node:
                  return 0 
              return 1 + Lheight(node.left)
          def Rheight(node):
              if not node:
                  return 0
              return 1 + Rheight(node.right)
          l, r = Lheight(root), Rheight(root)
          if l > r:
               return 1 + self.countNodes(root.left) + self.countNodes(root.right)
          else:
               return (2 ** l) - 1
         
if __name__ == "__main__":
        # Example usage
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.left.left = TreeNode(4)
        root.left.right = TreeNode(5)

        solution = Solution()
        print(solution.countNodes(root))  # Output: 5