class Solution:
    def longestCommonPrefix(self, strs) -> str:
        if len(strs) == 0 or "" in strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        common_prefix = ""
        for i in range(len(strs[0])):
            for word in strs[1:]:
                if i > len(word) - 1 or strs[0][i] != word[i]:
                    return common_prefix
            common_prefix = common_prefix + strs[0][i]
        return common_prefix