class Solution(object):
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        directions = [[0,1], [0,-1], [1,0], [-1,0]]

        n, m = len(maze), len(maze[0])
        q = deque()
        visit = set()

        q.append(start)
        visit.add(tuple(start))

        while q:
            x, y = q.popleft()
            if x==destination[0] and y==destination[1]:
                return True

            # roll as far as possible in each dir
            for d in directions:
                nx, ny = x+d[0], y+d[1]
                while 0 <= nx < n and 0 <= ny < m and maze[nx][ny] != 1:
                    nx += d[0]
                    ny += d[1]
                # move to last valid spot
                nx -= d[0]
                ny -= d[1]
                if (nx,ny) not in visit:
                    q.append((nx, ny))
                    visit.add((nx, ny))
        
        return False

# O(m*n) time, O(m*n) space

# python uses append for queue, instead of push / pop like c++
# python uses add for set instead of insert