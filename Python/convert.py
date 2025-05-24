class Solution(object):
    def convert(self, s, numRows):
        if numRows==1:
            return s
        result = ""
        for r in range (numRows):
            increment = 2*(numRows-1)
            for i in range(r,len(s), increment):
                result += s[i]
                if (r > 0 and r < numRows-1 and i+increment-2*r < len(s)):
                    result += s[i+increment-2*r]
        return result
    
# Example usage
if __name__ == "__main__":
    s = "PAYPALISHIRING"
    numRows = 3
    solution = Solution()
    result = solution.convert(s, numRows)
    print(result)  # Output: "PAHNAPLSIIGY"