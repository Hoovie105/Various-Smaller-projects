def jump(self, nums):
    n = len(nums)
    jumps = 0
    current_end = 0
    farthest = 0
    if n <= 1:
        return 0
    for i in range(n - 1):
        farthest = max(farthest, i + nums[i])
        
        if i == current_end:
            jumps += 1
            current_end = farthest

            if current_end >= n - 1:
                break

    return jumps


if __name__ == "__main__":
    nums = [2, 3, 1, 1, 4]
    print("Minimum jumps to reach the end:", jump(None, nums))  # Output: 2