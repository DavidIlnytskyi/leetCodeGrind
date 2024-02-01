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

/*
 Main Idea:

 Рухаємось з кінця на початок. Кожного разу перевіряємо,
 чи елемент більший за один з елементів, що був справа
 від нього. Якщо так - видаляємо елемент зі стаку, знову
 перевіряючи на більшість. Якщо знайшовся елемент в стаці
 що є більшим за поточний, то сетаєм позицію з індексом
 поточного елемента різницею елемента в стаці та поточного
 елемента. У кінці пушим поточний елемент. Таким чином у
 стаці зберігаються лише більші числа, що були знайдені
 протягом ітерацій.
 */