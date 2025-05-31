class Solution(object):
    def longestConsecutive(self, nums):
        num_set = set(nums)
        longest_streak = 0
        for num in num_set:
            if num - 1 not in num_set:
                length = 0
                while num + length in num_set:
                    length += 1
                longest_streak = max(longest_streak, length)
        return longest_streak

if __name__ == "__main__":
    # Example usage
    nums = [100, 4, 200, 1, 3, 2]
    solution = Solution()
    result = solution.longestConsecutive(nums)
    print(result)  # Output: 4 (the longest consecutive sequence is [1, 2, 3, 4])