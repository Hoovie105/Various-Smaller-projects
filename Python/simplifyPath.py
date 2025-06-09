class Solution(object):
    def simplifyPath(self, path):
          stack = []
          current = ""
          for c in path + "/":
              if c == "/":
                   if current == "..":
                        if stack:
                            stack.pop()
                   elif current != "" and current != ".":
                        stack.append(current)
                   current = ""
              else:
                current += c
          return "/" + "/".join(stack)                           

if __name__ == "__main__":
        # Example usage
        path = "/a/./b/../../c/"
        solution = Solution()
        result = solution.simplifyPath(path)
        print(result)  # Output: "/c"