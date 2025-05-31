class Solution(object):
    def isAnagram(self, s, t):
        # In case of different length of thpse two strings...
        if len(s) != len(t):
            return False
        for idx in set(s):
            # Compare s.count(l) and t.count(l) for every index i from 0 to 26...
            # If they are different, return false...
            if s.count(idx) != t.count(idx):
                return False
        return True 

if __name__ == "__main__":
    # Example usage
    s = "anagram"
    t = "nagaram"
    solution = Solution()
    result = solution.isAnagram(s, t)
    print(result)  # Output: True

    s = "rat"
    t = "car"
    result = solution.isAnagram(s, t)
    print(result)  # Output: False

    s = "listen"
    t = "silent"
    result = solution.isAnagram(s, t)
    print(result)  # Output: True