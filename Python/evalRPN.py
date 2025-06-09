class Solution(object):
    def evalRPN(self, tokens):
          stack = []
          for c in tokens:
              if c == "+":  
                  stack.append(stack.pop() + stack.pop())
              elif c == "-":
                  a, b = stack.pop(), stack.pop()
                  stack.append(b - a)
              elif c == "*":
                  stack.append(stack.pop() * stack.pop())
              elif c == "/":
                   a, b = stack.pop(), stack.pop()
                   stack.append(int(float(b) / a))
              else:
                  stack.append(int(c))
          return stack[0]


if __name__ == "__main__":
        # Example usage
        tokens = ["2", "1", "+", "3", "*"]
        solution = Solution()
        result = solution.evalRPN(tokens)
        print(result)  # Output: 9 (the expression evaluates to (2 + 1) * 3 = 9)
