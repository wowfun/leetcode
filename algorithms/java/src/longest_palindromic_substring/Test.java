package longestPalindromicSubstring;

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestPalindrome(""));
        System.out.println(s.longestPalindrome("ab"));
        System.out.println(s.longestPalindrome("abacab"));
    }
}
