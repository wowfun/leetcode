class Solution:
    def romanToInt(self, s: str) -> int:
        len_s = len(s)
        bases = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        n = 0
        i = 0
        while i < len_s:
            if len_s - 2 - i >= 0:
                curr = bases[s[len_s - 1 - i]] - bases[s[len_s - 2 - i]]
                if curr > 0:
                    n = n + curr
                    i = i + 2
                    continue
            n = n + bases[s[len_s - 1 - i]]
            i = i + 1
        return n


# test
print(Solution().romanToInt("MCMXCIV"))
