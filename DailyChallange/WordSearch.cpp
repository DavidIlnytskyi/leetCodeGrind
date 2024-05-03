/*
 https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03
 */
class Solution {
public:


    bool checkForWord(int idx, int jdx, vector<vector<char>>& board, string& word){
        if(!word.size())
            return true;
        if(idx < 0 || idx >= board.size() || jdx < 0 || jdx >= board[0].size() || word[0] != board[idx][jdx])
            return false;
        auto character = word[0];
        auto substr = word.substr(1);
        board[idx][jdx] = '*';
        auto result =   checkForWord(idx + 1, jdx, board, substr) ||
                        checkForWord(idx - 1, jdx, board, substr) ||
                        checkForWord(idx, jdx + 1, board, substr) ||
                        checkForWord(idx, jdx - 1, board, substr);
        board[idx][jdx] = character;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int idx = 0; idx < board.size(); ++idx){
            for(int jdx = 0; jdx < board[0].size(); ++jdx){
                if(checkForWord(idx, jdx, board, word))
                    return true;
            }
        }
        return false;
    }
};


/*
 Main idea:

 Iterate through every cell in board. For each cell
 call dfs, to check whether it is possible to find a
 word from it. If our cell letter is not equal to the
 corresponding letter in word, dfs returns false.
 In case it matches, we create substring to pass it
 for next check, and mark current cell as "*" to make
 using already used letters possible. Every call our
 substring loses first letter. If our substring is empty
 this means we have found all necessary letters.
 After calling dfs inside dfs, we change "*" to previous
 value to make it possible to find words with old chars
 */