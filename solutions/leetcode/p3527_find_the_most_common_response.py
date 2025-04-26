class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:
        responses = [list(set(r)) for r in responses]

        cnt = defaultdict(int)
        for r in responses:
            for w in r:
                cnt[w] += 1


        mx_cnt = 0
        mx_wrd = ""
        for w in cnt:
            if cnt[w] > mx_cnt:
                mx_cnt = cnt[w]
                mx_wrd = w
            elif cnt[w] == mx_cnt and w < mx_wrd:
                mx_wrd = w

        return mx_wrd