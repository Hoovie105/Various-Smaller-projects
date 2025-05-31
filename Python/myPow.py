class Solution(object):
    def myPow(self, x, n):
        def helper(x, n):
            if x == 0:
                return 0
            if n == 0:
                return 1
            res = helper(x, n // 2)
            res = res * res
            return res * x if n % 2 else res
        res = helper(x, abs(n))
        return res if n >= 0 else 1 / res
        
if __name__ == "__main__":
        # Example usage
        x = 2.0
        n = 10
        solution = Solution()
        result = solution.myPow(x, n)
        print(result)  # Output: 1024.0