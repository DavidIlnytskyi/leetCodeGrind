/*
    https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02
 */
class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        unordered_map<int, int> occurrences;
        int maxNumber = -1;
        for(auto number : nums){
            if(occurrences.find(-number) != occurrences.end())
                maxNumber = max(abs(number), maxNumber);
            else
                occurrences[number]++;
        }
        return maxNumber;
    }
};


/*
 Main idea:

 Iterate through each number, if negative of
 our number is present in the hashmap and is
 bigger than our current maximum, change the
 maximum. Add actual value to the map otherwise
 */