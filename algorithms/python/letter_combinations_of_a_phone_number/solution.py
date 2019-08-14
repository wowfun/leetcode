import itertools


class Solution:
    def letterCombinations(self, digits: str):
        if not digits:
            return []
        letters_map = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        return [''.join(x) for x in itertools.product(*[letters_map[int(d) - 2] for d in digits])]
