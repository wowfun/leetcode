package longestPalindromicSubstring;

class Solution {
    public boolean isPalindrome(String s, int i_l, int i_r) {
        while (i_l < i_r) {
            if (s.charAt(i_l) != s.charAt(i_r))
                return false;
            i_l++;
            i_r--;
        }
        return true;
    }

    public String longestPalindrome(String s) {
        if (!s.equals("")) {
            String max_substring = String.valueOf(s.charAt(0));
            ;
            for (int i_left = 0; i_left < s.length(); i_left++) {
                for (int i_right = s.length() - 1; i_right > i_left; i_right--) {
                    if (s.charAt(i_left) == s.charAt(i_right)) {
                        if (isPalindrome(s, i_left, i_right))
                            if (max_substring.length() < i_right - i_left + 1)
                                max_substring = s.substring(i_left, i_right + 1);
                    }
                }
            }
            return max_substring;
        }
        return s;
    }
}