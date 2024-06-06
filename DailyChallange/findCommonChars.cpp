/*
 https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;

        for(char character : words[0]){
            bool isCommon = true;

            for(int idx = 1; idx < words.size(); ++idx){
                if(words[idx].find(character) == string::npos){
                    isCommon = false;
                    break;
                } else
                    words[idx].erase(words[idx].find(character), 1);
            }
            if(isCommon)
                result.push_back(string(1, character));
        }
        return result;
    }
};

/*
 Main idea:

 If character is common, it has to be present in
 every word from first to last. So, we can take
 any word, and check every character, if it is
 present in every word. In case it is, we add
 this character to result, if not - skip this
 character and start to check next one.

 Important detail: if character from first word
 is present in any other word, first of all we
 need to delete this occurrence. This action
 will make algo capable to cope with duplicates.
 */