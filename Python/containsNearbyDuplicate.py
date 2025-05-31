class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        num_map = {}
        for i, num in enumerate(nums):
            if num in num_map and i - num_map[num] <= k:
                return True
            num_map[num] = i
        return False

if __name__ == "__main__":
    # Example usage
    nums = [1, 2, 3, 1]
    k = 3
    solution = Solution()
    result = solution.containsNearbyDuplicate(nums, k)
    print(result)  # Output: True

    nums = [1, 0, 1, 1]
    k = 1
    result = solution.containsNearbyDuplicate(nums, k)
    print(result)  # Output: True

    nums = [1, 2, 3, 1, 2, 3]
    k = 2
    result = solution.containsNearbyDuplicate(nums, k)
    print(result)  # Output: False