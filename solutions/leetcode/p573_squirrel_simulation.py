class Solution(object):
    def minDistance(self, height, width, tree, squirrel, nuts):
        """
        :type height: int
        :type width: int
        :type tree: List[int]
        :type squirrel: List[int]
        :type nuts: List[List[int]]
        :rtype: int
        """
        def dist(a, b):
            return abs(a[0]-b[0]) + abs(a[1]-b[1])

        total_dist = 0
        max_savings = float('-inf')
        for nut in nuts:
            total_dist += dist(nut, tree)*2
            max_savings = max(max_savings, dist(nut,tree)*2 - (dist(nut, tree)+dist(nut,squirrel)))

        return total_dist - max_savings
        
# bfs without checking for savings is not necessarily optimal, a nut may be closer to the squirrel, but save less
# calculate dist from tree to nut * 2 for each nut
# calculate max savings by checking savings if we go to that nut first
# we can use total distance BECAUSE THERE IS NO OBSTACLES