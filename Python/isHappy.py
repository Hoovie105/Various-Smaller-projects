class Solution(object):
    def isHappy(self, n):
        if(n==1 or n==7):
            return True
        elif(n<10):
            return False
        else:
            sum =0
            while(n>0):
                temp = n%10
                sum += temp*temp
                n= n//10
            return self.isHappy(sum) 

if __name__ == "__main__":
    # Example usage
    n = 19
    solution = Solution()
    result = solution.isHappy(n)
    print(result)  # Output: True

    n = 2
    result = solution.isHappy(n)
    print(result)  # Output: False