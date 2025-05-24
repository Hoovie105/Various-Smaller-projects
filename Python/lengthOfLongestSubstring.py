class Solution(object):
    def lengthOfLongestSubstring(self, s):
          l, result = 0, 0
          chars = set()
          for r in range(len(s)):
              while s[r] in chars:
                    chars.remove(s[l])
                    l += 1
              chars.add(s[r])
              result = max(result, r - l + 1)
          return result

if __name__ == "__main__":
        # Example usage
        s = "abcabcbb"
        solution = Solution()
        result = solution.lengthOfLongestSubstring(s)
        print(result)  # Output: 3
        # Explanation: The answer is "abc", with the length of 3.
        # Note: The code above is a placeholder and does not implement the actual logic.