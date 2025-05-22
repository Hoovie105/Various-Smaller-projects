class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        while val in nums:
            nums.remove(val)
        return len(nums)
        
# Example usage:
if __name__ == "__main__":
    solution = Solution()
    nums = [3, 2, 2, 3]
    val = 3
    length = solution.removeElement(nums, val)
    print("Length of the array after removing elements:", length)
    print("Modified array:", nums[:length])
