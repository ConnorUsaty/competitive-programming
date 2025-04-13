class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cnt = Counter(t)
        missing = len(cnt)

        i = 0
        l = 0
        r = float('inf')
        for j in range(len(s)):
            if s[j] in cnt:
                cnt[s[j]] -= 1
                if cnt[s[j]] == 0:
                    missing -= 1
            
            while missing == 0:
                if j-i < r-l:
                    r = j
                    l = i
                if s[i] in cnt:
                    cnt[s[i]] += 1
                    if cnt[s[i]] > 0:
                        missing += 1
                i += 1

        return s[l:r+1] if r != float('inf') else ""
