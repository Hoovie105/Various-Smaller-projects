import collections
class Solution(object):
    def maxPoints(self, points):
        result = 1
        for i in range(len(points)):
            p1 = points[i]
            count = collections.defaultdict(int)
            for j in range(i + 1, len(points)):
                p2 = points[j]
                if p1[0] == p2[0]:
                    slope = float('inf')
                else:
                    slope = (p2[1] - p1[1]) / (p2[0] - p1[0])
                count[slope] += 1
                result = max(result, count[slope] + 1)
        return result


if __name__ == "__main__":
    # Example usage
    points = [0,0],[4,5],[7,8],[8,9],[5,6],[3,4],[1,1]
    solution = Solution()
    result = solution.maxPoints(points)
    print(result)  # Output: 3 (all points are collinear)