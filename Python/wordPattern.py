class Solution(object):
    def wordPattern(self, pattern, s):
        words = s.split(" ")
        if len(pattern) != len(words):
            return False
        char_to_word = {}
        word_to_char = {}
        for char, word in zip(pattern, words):
            if char in char_to_word and char_to_word[char] != word:
                return False
            if word in word_to_char and word_to_char[word] != char:
                return False
            char_to_word[char] = word
            word_to_char[word] = char
        return True

if __name__ == "__main__":
    s = Solution()
    print(s.wordPattern("abba", "dog cat cat dog"))  # True
    print(s.wordPattern("abba", "dog cat cat fish"))  # False
    print(s.wordPattern("aaaa", "dog cat cat dog"))  # False
    print(s.wordPattern("abba", "dog dog dog dog"))  # False