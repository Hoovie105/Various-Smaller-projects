class Solution:
    def fullJustify(self, words, maxWidth):
        res, cur, num_of_letters = [], [], 0
        for w in words:
            if num_of_letters + len(w) + len(cur) > maxWidth:
                for i in range(maxWidth - num_of_letters):
                    cur[i % (len(cur) - 1 or 1)] += ' '
                res.append(''.join(cur))
                cur, num_of_letters = [], 0
            cur += [w]
            num_of_letters += len(w)
        return res + [' '.join(cur).ljust(maxWidth)]

if __name__ == "__main__":
        words = ["This", "is", "an", "example", "of", "text", "justification."]
        maxWidth = 16
        solution = Solution()
        result = solution.fullJustify(words, maxWidth)
        for line in result:
            print(f'"{line}"')