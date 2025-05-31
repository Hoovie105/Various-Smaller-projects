class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []

        word_length = len(words[0])
        word_count = len(words)
        total_length = word_length * word_count
        word_map = {}

        for word in words:
            if word in word_map:
                word_map[word] += 1
            else:
                word_map[word] = 1

        result = []
        for i in range(len(s) - total_length + 1):
            seen_words = {}
            for j in range(word_count):
                start_index = i + j * word_length
                end_index = start_index + word_length
                current_word = s[start_index:end_index]

                if current_word not in word_map:
                    break

                if current_word in seen_words:
                    seen_words[current_word] += 1
                else:
                    seen_words[current_word] = 1

                if seen_words[current_word] > word_map[current_word]:
                    break

            if seen_words == word_map:
                result.append(i)

        return result

if __name__ == "__main__":
    s = "barfoothefoobarman"
    words = ["foo", "bar"]
    solution = Solution()
    result = solution.findSubstring(s, words)
    print(result)  # Output: [0, 9]