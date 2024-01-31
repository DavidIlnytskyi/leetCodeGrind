//
// Created by David on 31.01.2024.
//
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int size = temperatures.size();
        vector<int>path(size, 0);
        stack<int> stck;
        for(int i = size-1; i >= 0; --i){
            while(!stck.empty() && temperatures[i] >= temperatures[stck.top()])
                stck.pop();

            if(!stck.empty())
                path[i] = stck.top() - i;

            stck.push(i);
        }

        return path;
    }
};