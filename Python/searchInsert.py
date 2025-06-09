class Solution(object):
    def searchInsert(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left
                
if __name__ == "__main__":
    # Example usage
    nums = [1, 3, 5, 6]
    target = 5
    solution = Solution()
    result = solution.searchInsert(nums, target)
    print(result)  # Output: 2 (5 is at index 2)