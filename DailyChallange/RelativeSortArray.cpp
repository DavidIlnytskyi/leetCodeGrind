/*
 https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11
 */

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        /*
        arr1 - all numbers
        arr2 - numbers order
        */

        vector<int> frequency(1001, 0);
        for(auto number : arr1)
            frequency[number]++;

        vector<int> result;

        for(auto number : arr2){
            while(frequency[number] > 0){
                result.push_back(number);
                frequency[number]--;
            }
        }

        for(int idx = 0; idx < 1001; ++idx){
            while(frequency[idx] > 0){
                result.push_back(idx);
                frequency[idx]--;
            }
        }
        return result;
    }
};

/*
 Main idea:

 Calculate number of occurrences of each number
 Iterate through order array, for each number
 push this number to the end of result array
 while number of his occurrences is > 0, decrs occurr by 1
 Iterate through occurrences array, if our number
 still has occurrences, add this number to the end
 of result array. As our occurrences array is also sorted,
 our array gonna be also sorted
 */