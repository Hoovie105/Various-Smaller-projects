class Solution(object):
    def maxProfit(self, prices):
        profit = 0

        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit
    
# Example usage
if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]
    solution = Solution()
    result = solution.maxProfit(prices)
    print(result)  # Output: 7