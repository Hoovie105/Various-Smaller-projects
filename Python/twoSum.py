class Solution(object):
    def twoSum(self, numbers, target):
        left = 0
        right = len(numbers) - 1
        while left < right:
            currsum = numbers[left] + numbers[right]
            if currsum == target:
                return [left + 1, right + 1] # 1-based index conversion.
            elif currsum < target:
                left += 1
            else:
                right -= 1
        return []
  
# Example usage:
if __name__ == "__main__":
    sol = Solution()
    print(sol.twoSum([2, 7, 11, 15], 9))  # Output: [1, 2]
