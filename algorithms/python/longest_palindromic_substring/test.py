class Solution:
    def longestPalindrome(self, s: str) -> str:
        # under certain conditions, the longest common substring of s and  reserved s is the answer
        reverse_s = s[::-1]
        len_s = len(s)
        if len_s <= 1:
            return s
        else:
            curr_len = [[0] * (1 + len_s) for i in range(1 + len_s)]
            longest, i_longest = 0, 0
            for i in range(1, 1 + len_s):
                for j in range(1, 1 + len_s):
                    if s[i - 1] == reverse_s[j - 1]:
                        curr_len[i][j] = curr_len[i - 1][j - 1] + 1
                        if curr_len[i][j] > longest:
                            longest_substring_to_test = s[(i - curr_len[i][j]):i]
                            if longest_substring_to_test == longest_substring_to_test[::-1]:
                                longest = curr_len[i][j]
                                i_longest = i
                    else:
                        curr_len[i][j] = 0
            return s[(i_longest - longest):i_longest]


if __name__ == '__main__':
    s = Solution()
    print(s.longestPalindrome(""))
    print(s.longestPalindrome("a"))
    print(s.longestPalindrome("abcdcb"))
    print(s.longestPalindrome("aacdefcaa"))
