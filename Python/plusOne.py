class Solution(object):
    def plusOne(self, digits):
        # Start with a carry of 1, since we are adding one to the number
        carry = 1
        # Iterate over the digits from right to left
        for i in range(len(digits) - 1, -1, -1):
            if carry == 0:
                break  # No more carry to add, exit early
            digits[i] += carry  # Add carry to the current digit
            if digits[i] == 10:
                digits[i] = 0  # Set to 0 and keep carry for the next digit
                carry = 1
            else:
                carry = 0  # No carry needed, addition complete
        # If there's still a carry after the loop, insert 1 at the front
        if carry == 1:
            digits.insert(0, 1)
        return digits

if __name__ == "__main__":
    # Example usage
    digits = [1, 2, 3]
    solution = Solution()
    result = solution.plusOne(digits)
    print(result)  # Output: [1, 2, 4]
    digits = [9, 9, 9]
    result = solution.plusOne(digits)
    print(result)  # Output: [1, 0, 0, 0]
