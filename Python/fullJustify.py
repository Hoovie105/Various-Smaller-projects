class Solution(object):
    def fullJustify(self, words, maxWidth):
         result = []
         currline, length = [], 0
         i = 0

         while i < len(words):
              if length + len(currline) + len(words[i]) > maxWidth:
                   extraspaces = maxWidth - length
                   spaces = extraspaces // max(1, len(currline) - 1)
                   remainder = extraspaces % max(1, len(currline) - 1)

                   for j in range(len(currline) - 1):
                        currline[j] += ' ' * spaces
                        if remainder:
                                currline[j] += ' '
                                remainder -= 1
                   result.append("".join(currline))
                   currline, length = [], 0

              currline.append(words[i])
              length += len(words[i])
              i += 1

         last_line = " ".join(currline)
         trail_spaces = maxWidth - len(last_line)
         result.append(last_line + " " * trail_spaces)
         return result

if __name__ == "__main__":
        words = ["This", "is", "an", "example", "of", "text", "justification."]
        maxWidth = 16
        solution = Solution()
        result = solution.fullJustify(words, maxWidth)
        for line in result:
            print(f'"{line}"')