/*
 * https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01
 */


class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for(int idx = 0; idx < s.size() - 1; ++idx){
            result += std::abs(s[idx + 1] - s[idx]);
        }
        return result;
    }
};

/*
 Main idea:

 As in C++ in math operations chars are
 read as their ASCII codes, we can
 manipulate with them without using
 any interfaces

 To calculate absolute difference between
 each adjacent character we have to iterate
 through every character from 0 to n-2
 and from next character substract current
 character, and add to the total result
 At the end, add this to total result.
 */