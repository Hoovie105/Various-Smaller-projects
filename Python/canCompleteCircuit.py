class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        
        total = 0
        res = 0
        start = 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            if total < 0:
                total = 0
                start = i + 1
        return start
    
# Example usage
if __name__ == "__main__":
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    solution = Solution()
    result = solution.canCompleteCircuit(gas, cost)
    print(result)  # Output: 3

# The output indicates that starting from station 3 allows for a complete circuit.
# The function checks if the total gas is less than the total cost, in which case it returns -1.
# Otherwise, it iterates through the gas stations, calculating the total gas and cost.
# If the total gas becomes negative, it resets the total and updates the starting station.
# The final result is the starting station index from which a complete circuit can be made.
# The time complexity is O(n), where n is the number of gas stations.
# The space complexity is O(1) since we are using a constant amount of space.