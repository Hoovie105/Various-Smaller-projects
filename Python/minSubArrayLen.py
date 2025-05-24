class Solution(object):
    def minSubArrayLen(self, target, nums):
        l, total = 0, 0
        result = float('inf')
        for r in range(len(nums)):
            total += nums[r]
            while total >= target:
                result = min(result, r - l + 1)
                total -= nums[l]
                l += 1
        return 0 if result == float('inf') else result

if __name__ == "__main__":
    # Example usage
    target = 7
    nums = [2, 3, 1, 2, 4, 3]
    solution = Solution()
    result = solution.minSubArrayLen(target, nums)
    print(result)  # Output: 2