class Solution(object):
    def climbStairs(self, n):
        one, two = 1, 1
        for i in range (n - 1):
            temp = one
            one = one + two
            two = temp
        return one

if __name__ == "__main__":
    # Example usage
    n = 5
    solution = Solution()
    result = solution.climbStairs(n)
    print(result)  # Output: 8 (the number of distinct ways to climb 5 stairs)