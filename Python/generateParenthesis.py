class Solution(object):
    def generateParenthesis(self, n):
        def backtrack(current, open_count, close_count):
            if len(current) == 2 * n:
                result.append(current)
                return
            if open_count < n:
                backtrack(current + '(', open_count + 1, close_count)
            if close_count < open_count:
                backtrack(current + ')', open_count, close_count + 1)

        result = []
        backtrack('', 0, 0)
        return result

if __name__ == "__main__":
        # Example usage
        n = 3
        solution = Solution()
        result = solution.generateParenthesis(n)
        print(result)  # Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]