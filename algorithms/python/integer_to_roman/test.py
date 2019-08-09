class Solution:
    def intToRoman(self, num: int) -> str:
        ns = str(num)
        num_roman = ""
        bases_one = "IXCM"
        bases_five = "VLD"
        end_ns = len(ns) - 1
        for i in range(end_ns + 1):
            n_remainder = int(ns[end_ns - i]) % 10
            if n_remainder == 9:
                num_roman = num_roman + bases_one[i + 1] + bases_one[i]
            elif 5 < n_remainder < 9:
                num_roman = num_roman + bases_one[i] * (n_remainder - 5) + bases_five[i]
            elif n_remainder == 5:
                num_roman = num_roman + bases_five[i]
            elif n_remainder == 4:
                num_roman = num_roman + bases_five[i] + bases_one[i]
            elif 0 < n_remainder < 4:
                num_roman = num_roman + bases_one[i] * n_remainder
        return num_roman[::-1]


# test
print(Solution().intToRoman(58))
