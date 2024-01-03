class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sizeBank = bank.size();
        int previousValue = 0;
        int value = 0;
        int result = 0;
        for(int idx = 0; idx < sizeBank; ++idx){
            for(char character : bank[idx]){
                if(character == '1'){
                    value += 1;
                }
            }
            if(previousValue != 0 && value != 0){
                result += value * previousValue;
            }
            if(previousValue != 0 && value == 0){
                continue;
            }
            previousValue = value;
            value = 0;
        }
        return result;
    }
};

/*
Main idea:

Задано масив рядків з 1 або 0.
Якщо 1 - там є лазер, 0 - відповідно немає

Завдання порахувати кількість з'єднань між лазерами
Лазер може з'єднюватись з іншим лазером лише якщо той
в іншому рядку, і якщо на їхньому шляху немає інших лазерів.

Головна ідея в тому, щоб зберігати кількість лазерів на
попередньому рядку. Якщо вона і кількість лазерів на
цьому рядку не дорівнюють нулю, додати добуток кількості
лазерів на цих рядках до результату.

Якщо на попередньому рядку були лазери, а на даному ні -
ми не оновлюємо значення лазерів на попередньому. Не оновлюєм
допоки теперішній рядок не буде мати значення != 0.

Оновлення значення лазерів на попередньому рядку відбувається
завжди, якщо на поточному рядку є лазери.
 */