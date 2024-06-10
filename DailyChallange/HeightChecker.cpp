/*
 https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
 */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> frequency(101, 0);
        for(auto value : heights){
            frequency[value]++;
        }
        int result = 0;
        int currentValue = 1;

        for(auto value : heights){
            while(frequency[currentValue] == 0)
                ++currentValue;
            if(currentValue != value)
                result++;
            frequency[currentValue]--;
        }
        return result;
    }
};


/*
 Main idea:

 We calculate how many occurrences of each number are
 present in the array. After, for each unique number
 from 1 to 100, if this number is present, it
 has to be at current position(0 for 1), as we go from the
 smallest to the biggest, and our array has to
 be sorted in non-decreasing order. If unique and current
 number are not equal, then current value is wrong
 Otherwise, we decrease number of occurrences of current
 value by one, as we have found 1 right occurrence
 and move our current pointer to the next value
 */