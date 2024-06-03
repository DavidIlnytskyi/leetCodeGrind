/*
 https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/?envType=daily-question&envId=2024-06-03
 */

class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        int jdx = 0;
        while(idx < s.size() && jdx < t.size()){
            if(s[idx] == t[jdx])
                jdx++;
            idx++;
        }
        return t.size() - jdx;
    }
};

/*
 Main idea:

 Iterate through main character string
 if character corresponds to char in
 substring, increase jdx of substring,
 it will be possible to check next
 character for correspondence.

 if current character equals with char
 in substring, change character that is
 being checked to next character
 if not, just continue searching for idx
 that will correspond to current character
 */