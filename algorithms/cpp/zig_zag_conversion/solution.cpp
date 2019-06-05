#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1)
            return s;
        string result="";
        int numCols = s.length();
        int k = 0;
        char **pattern = new char *[numRows];
        for (int i = 0; i < numRows; i++)
            pattern[i] = new char[numCols];
        for (int j = 0; j < numCols; ++j) {
            for (int i = 0; i < numRows; i++) {
                if ((j % (numRows - 1) == 0 || i + j % (numRows - 1) == numRows - 1 )&& k < numCols) {
                    pattern[i][j] = s[k++];
                } else {
                    pattern[i][j] = ' ';
                }
            }
        }
        k=0;
        for (int i = 0; i < numRows && k<numCols; i++) {
            for (int j = 0; j < numCols; j++) {
                if (pattern[i][j]!=' '){
                    result=result+pattern[i][j];
                }
            }
        }
        return result;
    }
};