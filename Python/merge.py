class Solution(object):
    def merge(self, intervals):
        intervals.sort(key=lambda i: i[0])
        output = [intervals[0]]
        for start, end in intervals[1:]:
            lastEnd = output[-1][1]
            if start <= lastEnd:
                output[-1][1] = max(lastEnd, end)
            else:
                output.append([start, end])
        return output

if __name__ == "__main__":
    # Example usage
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
    solution = Solution()
    result = solution.merge(intervals)
    print(result)  # Output: [[1, 6], [8, 10], [15, 18]]