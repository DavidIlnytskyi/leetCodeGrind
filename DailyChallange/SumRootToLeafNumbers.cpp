/*
 https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15
 */

class Solution {
public:
    int sumNumbers(TreeNode* root, int currentValue = 0) {
        if(!root)
            return 0;

        currentValue = currentValue * 10 + root -> val;

        if(!(root -> left || root -> right)){
            return currentValue;
        }

        return sumNumbers(root->left, currentValue) + sumNumbers(root->right, currentValue);
    }
};

/*
 Main idea:

 Головна ідея в тому, що ми завжди повертаємо
 суму обчислення лівого та правого синів, якщо їх
 немає, ми в останньому сині -> повертаємо шлях.

 Якщо нода не існує, то на попередньому виклиці
 були в листку, що має лише одного сина.
 Повертаємось та продовжуємо
 рахувати суму для сина листка.

 Якщо на якомусь етапі в листка немає синів,
 то ми повертаємо шлях, що накопичили до цього
 кроку. Це значення підіймається вверх, допоки
 не зустріне батька, в якого був ще один син, та
 почне рахувати для іншого сина його шлях.

 */