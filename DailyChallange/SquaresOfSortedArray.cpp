/*
 https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int numberOfElements = nums.size();
        int leftPtr = 0;
        int rightPtr = numberOfElements - 1;
        int idx = numberOfElements - 1;
        while(idx >= 0){
            if(abs(nums[leftPtr]) >= abs(nums[rightPtr])){
                result[idx] = pow(nums[leftPtr], 2);
                leftPtr++;
            } else{
                result[idx] = pow(nums[rightPtr], 2);
                rightPtr--;
            }
            idx--;
        }
        return result;
    }
};


/*
 Main idea:

 We have sorted sequence from the smallest negative to
 the biggest positive number. Our goal is to compare
 what is bigger, absolute value of negative number or
 positive number itself. To do that, we are doing two
 pointers. One for start(for neg numbers), and other
 for the end(for pos numbers). After, we are comparing
 those pointers values to get bigger number. After add
 square of that number to the resulting sequence.

 Compare what is bigger, negative or positive number,
 and add resulting number to the sequence.
 */