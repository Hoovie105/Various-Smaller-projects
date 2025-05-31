class Solution(object):
    def insert(self, intervals, newInterval):
        result = []  # This will store the merged intervals

        for i in range(len(intervals)):
            # If the new interval ends before the current interval starts, insert it here
            if newInterval[1] < intervals[i][0]:
                result.append(newInterval)
                return result + intervals[i:]  # Add the rest of the intervals as is
            # If the new interval starts after the current interval ends, add the current interval
            elif newInterval[0] > intervals[i][1]:
                result.append(intervals[i])
            else:
                # Overlapping intervals: merge by updating the new interval's start and end
                newInterval[0] = min(newInterval[0], intervals[i][0])
                newInterval[1] = max(newInterval[1], intervals[i][1])
        # If newInterval hasn't been added yet, add it at the end
        result.append(newInterval)
        return result

if __name__ == "__main__":
    # Example usage
    intervals = [[1, 3], [6, 9]]
    newInterval = [2, 5]
    solution = Solution()
    result = solution.insert(intervals, newInterval)
    print(result)  # Output: [[1, 5], [6, 9]]