class Solution(object):
    def findMinArrowShots(self, points):
          points.sort()
          result = len(points)
          prev = points[0]
          for i in range(1, len(points)):
              curr = points[i]
              if curr[0] <= prev[1]:
                    result -= 1
                    prev = [curr[0], min(prev[1], curr[1])]
              else:
                    prev = curr
          return result

if __name__ == "__main__":
        # Example usage
        points = [[10, 16], [2, 8], [1, 6], [7, 12]]
        solution = Solution()
        result = solution.findMinArrowShots(points)
        print(result)  # Output: 2 (we can shoot arrows at points 6 and 12)