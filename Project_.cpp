#include <iostream>
#include <string>
#include "sum_of_squares.h"
using namespace std;
int main() {
    string n;
    // Запрос числа
    cout << "Введите число n (n >= 20000): ";
    cin >> n;
    // Проверка на корректность ввода
    if (!is_valid_input(n)) {
        return 1; // Завершаем программу с ошибкой
    }
    // Вычисляем сумму квадратов от 1 до n
    string result = sum_of_squares(n);
    cout << "Сумма квадратов от 1 до " << n << " равна: " << result << endl;
    return 0;
}
