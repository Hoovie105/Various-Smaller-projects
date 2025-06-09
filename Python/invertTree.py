class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def invertTree(self, root):
         if not root:
              return None
         # Swap the left and right children
         tmp = root.left
         root.left = root.right
         root.right = tmp
         self.invertTree(root.left)  # Recursively invert the left subtree
         self.invertTree(root.right)  # Recursively invert the right subtree
         return root

if __name__ == "__main__":
        # Example usage
        root = TreeNode(4)
        root.left = TreeNode(2)
        root.right = TreeNode(7)
        root.left.left = TreeNode(1)
        root.left.right = TreeNode(3)
        root.right.left = TreeNode(6)
        root.right.right = TreeNode(9)

        solution = Solution()
        inverted_root = solution.invertTree(root)

        # Function to print the tree in-order for verification
        def print_in_order(node):
            if node:
                print_in_order(node.left)
                print(node.val, end=' ')
                print_in_order(node.right)

        print_in_order(inverted_root)  # Output should be the inverted tree in-order traversal