class Solution(object):
    def twoSum(self, numbers, target):
        map_index = {}
        for i, num in enumerate(numbers):
            diff = target - num
            if diff in map_index:
                return [map_index[diff], i]
            map_index[num] = i
        return []


if __name__ == "__main__":
    # Example usage:
    sol = Solution()
    print(sol.twoSum([2, 7, 11, 15], 9))  # Output: [1, 2]
    print(sol.twoSum([1, 2, 3, 4, 6], 10))  # Output: [4, 5]
    print(sol.twoSum([-1, 0], -1))  # Output: [1, 2]