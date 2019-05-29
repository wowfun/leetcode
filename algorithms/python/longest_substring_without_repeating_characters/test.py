class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        len_s = len(s)
        for left in range(len_s):
            cur_len = 1
            cur_substring = s[left]
            for right in range(left + 1, len_s):
                if s[left] != s[right] and (s[right] not in cur_substring):
                    cur_substring = cur_substring + s[right]
                    cur_len = cur_len + 1
                else:
                    break
            if cur_len > max_len:
                max_len = cur_len
        return max_len

    def test(self):
        print(self.lengthOfLongestSubstring(""))
        print(self.lengthOfLongestSubstring(" "))
        print(self.lengthOfLongestSubstring("bbbbb"))
        print(self.lengthOfLongestSubstring("pwwkew"))


if __name__ == '__main__':
    s1 = Solution()
    s1.test()
