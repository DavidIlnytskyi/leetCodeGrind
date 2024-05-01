/*
https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01
 */
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int charPosition = word.find(ch);
        if(charPosition != string::npos)
            reverse(word.begin(), word.begin() + charPosition + 1);
        return word;
    }
};

/*
 Main idea:

 Find position of this char in our string
 If this char is present, which means
 charPosition != string::npos, we call
 reverse function from the beginning
 of the word, to the position, where char
 was found. As the goal is to be inclusive,
 we have to increase our end position by 1,
 so reverse function will include our character
 */