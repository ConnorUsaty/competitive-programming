class Solution(object):
    def generateSentences(self, synonyms, text):
        """
        :type synonyms: List[List[str]]
        :type text: str
        :rtype: List[str]
        """
        if len(synonyms) == 0:
            return [text]
        
        adj = defaultdict(list)
        for s in synonyms:
            adj[s[0]].append(s[1])
            adj[s[1]].append(s[0])
            
        words = text.split(' ')
        ans = []
        visited = set()
        
        def backtrack(i, visited):
            if i == len(words):
                ans.append(" ".join(words))
                return
            
            orig = words[i]
            visited.add(tuple((orig, i)))
            
            for synonym in adj[orig]:
                if tuple((synonym, i)) not in visited:
                    words[i] = synonym
                    backtrack(i, visited)
            
            visited.remove(tuple((orig, i))) 
            words[i] = orig
            backtrack(i+1, visited)
                    
        backtrack(0, visited)
        ans.sort()
        return ans

# Have to return all combinations of something -> BACKTRACKING
# In this case need to dfs with visited set to perform the correct backtracking
# For dfs add to visited when called, not when pushing
# Have to remove from visited / clean up at end so that another path can visit