class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):
    def hasPathSum(self, root, targetSum):
        def dfs(root, curSum):
            if not root:
                return False
            curSum += root.val
            if not root.left and not root.right:
                return curSum == targetSum
            return dfs(root.left, curSum) or dfs(root.right, curSum)
        return dfs(root, 0)

if __name__ == "__main__":
    # Example usage:
    # Constructing a binary tree:
    #       5
    #      / \
    #     4   8
    #    /   / \
    #   11  13  4
    #  /  \      \
    # 7    2      1
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)

    targetSum = 22

    solution = Solution()
    print(solution.hasPathSum(root, targetSum))  # Output: True or False based on the path sum