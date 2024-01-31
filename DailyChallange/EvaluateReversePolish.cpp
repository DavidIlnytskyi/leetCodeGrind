/*
 https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int intOne, intTwo;

        for(string character : tokens) {
            if (character.size() > 1 || isdigit(character[0])) {
                numbers.push(stoi(character));
                continue;
            }

            intOne = numbers.top(); numbers.pop();
            intTwo = numbers.top(); numbers.pop();

            if (character[0] == '*') {
                numbers.push(intTwo * intOne);
            } else if (character[0] == '/') {
                numbers.push(intTwo / intOne);
            } else if (character[0] == '-') {
                numbers.push(intTwo - intOne);
            } else if (character[0] == '+') {
                numbers.push(intTwo + intOne);
            }
        }
        return numbers.top();
    }
};


