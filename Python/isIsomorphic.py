class Solution(object):
    def isIsomorphic(self, s, t):
        if len(s) != len(t):
            return False
        char_map_s_to_t = {}
        char_map_t_to_s = {}
        for char_s, char_t in zip(s, t):
            if char_s in char_map_s_to_t:
                if char_map_s_to_t[char_s] != char_t:
                    return False
            else:
                char_map_s_to_t[char_s] = char_t
            
            if char_t in char_map_t_to_s:
                if char_map_t_to_s[char_t] != char_s:
                    return False
            else:
                char_map_t_to_s[char_t] = char_s
        return True
        
if __name__ == "__main__":
    # Example usage
    s = "egg"
    t = "add"
    solution = Solution()
    result = solution.isIsomorphic(s, t)
    print(result)  # Output: True

    s = "foo"
    t = "bar"
    result = solution.isIsomorphic(s, t)
    print(result)  # Output: False

    s = "paper"
    t = "title"
    result = solution.isIsomorphic(s, t)
    print(result)  # Output: True