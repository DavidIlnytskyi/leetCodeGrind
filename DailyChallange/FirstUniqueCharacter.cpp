//
// Created by David on 05.02.2024.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charFrequency(26, 0);
        vector<int> charIndexes(26, 0);
        for(int idx = 0; idx < s.size(); ++idx){
            charFrequency[s[idx] - 'a']++;
            charIndexes[s[idx] - 'a'] = idx;
        }
        for(int idx = 0; idx < 26; ++idx){
            if(charFrequency[idx] == 1)
                return charIndexes[idx];
        }
        return -1;
    }
};

int main(){
    cout << Solution().firstUniqChar("leetcode");
    return 1;
}