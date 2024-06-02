/*
 https://leetcode.com/problems/reverse-string/description/?envType=daily-question&envId=2024-06-02
 */


class Solution {
public:
    void reverseString(vector<char>& s) {
        /*
         This code also works
         std::reverse(s.begin(), s.end());
         */
        for(int idx = 0; idx < s.size()/2; ++idx){
            auto temp = s[idx];
            s[idx] = s[s.size() - idx - 1];
            s[s.size() - idx - 1] = temp;
        }
    }
};


/*
 Main idea:

 Iterate to the middle of the array,
 while n-th number from the start
 with n-th number from the end;

 If word length is odd
 The middle character is not
 touched, while characters around
 are being swapped.

 Math is:
 Length of 5 is divided by 2, in c++
 we get 2, so we will iterate through
 0,1
 first h, e, will be changed with l, o
 in accordance
 */
