class Solution(object):
    def mySqrt(self, x):
        if x == 0:
            return 0
        left, right = 1, x
        while left <= right:
            mid = (left + right) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                left = mid + 1
            else:
                right = mid - 1
        return right
    
if __name__ == "__main__":
        # Example usage
        x = 15
        solution = Solution()
        result = solution.mySqrt(x)
        print(result)  # Output: 2 (since sqrt(8) is approximately 2.828, we return the integer part which is 2)