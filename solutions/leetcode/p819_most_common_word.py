class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        banned = set(banned)
        words = re.split(r"[\W']+", paragraph, flags=re.IGNORECASE)
        
        mx_cnt = -1
        mx_w = ""
        cnt = defaultdict(int)
        for w in words:
            w = w.lower()
            if w in banned:
                continue
                
            cnt[w] += 1
            if cnt[w] > mx_cnt:
                mx_cnt = cnt[w]
                mx_w = w
                
        return mx_w
                
# re.split(pattern, string) splits string on anything that matches pattern