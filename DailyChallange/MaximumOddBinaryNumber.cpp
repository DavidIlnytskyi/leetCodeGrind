/*
 https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
 */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCounter = 0;
        for(auto character : s)
            if(character == '1')
                oneCounter++;
        string result(oneCounter - 1, '1');
        for(int idx = 0; idx < s.size() - oneCounter; ++idx){
            result += '0';
        }
        result += '1';

        return result;
    }
};

/*
 Main idea:

 Count all occurrences of 1. After that, add first k-1
 occurrences to the beginning. After that, add n - k
 zeros to the middle of word. At the end, add 1 to the
 end of word. So, what we have:
 1. Add possible 1 to the start, so we get as big binary
 number as possible.
 2. Fulfill the rest of word of 0
 3. Insert 1 to the end as this has to be odd number
 */