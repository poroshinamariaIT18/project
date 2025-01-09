#include "sum_of_squares.h"
#include <iostream>
#include <string> // для работы со строками
#include <cstdlib> // для работы с числовыми функциями, например преобразование строки в число
#include <cmath>// для работы с математическими функциями
using namespace std;
// Функция для преобразования числа в строку
string to_str(long long int m) {
	return to_string(m); 
}
// Умножение больших чисел, представленных строками, способом умножения столбиком
string multiply_large_numbers(string a, string b) {
    int len_a = a.length();
	int len_b = b.length(); // длины строк a и b 
	int result_len = len_a + len_b;  // длина результирующей строки равна сумме длин a и b
	int* result = new int[result_len](); // динамический массив для хранения результата умножения
   //два вложенных цикла, которые проходят по всем цифрам чисел в строках а и b начиная с младщих разрядов
    for (int i = len_a - 1; i >= 0; --i) { 
        for (int j = len_b - 1; j >= 0; --j) { 
            int mul = (a[i] - '0') * (b[j] - '0');// перемножаем цифры из строк 
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;// младшую цифру рез-та в тек.позицию
			result[i + j] += sum / 10;// старшую цифру рез-та в предыдущую позицию
        }
    }

    // Преобразуем результат в строку,проходим по массиву собирая строку рез-та пропуская ведущие нули
    string result_str = "";
    for (int i = 0; i < result_len; ++i) {
        if (!(result_str.empty() && result[i] == 0)) {
            result_str += (result[i] + '0');
        }
    }
    delete[] result;
    return result_str.empty() ? "0" : result_str;
}

// Деление больших чисел на 6
string divide_large_number_by_6(string n) {
    int remainder = 0;
    string result = "";

    for (char c : n) {
        int current = remainder * 10 + (c - '0');
        result += (current / 6) + '0';
        remainder = current % 6;
    }

    // Убираем ведущие нули
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

// Функция для вычисления суммы квадратов от 1 до n  по формуле
string sum_of_squares(string n_str) {
    string n_plus_1 = to_str(stoi(n_str) + 1);
    string two_n_plus_1 = to_str(2 * stoi(n_str) + 1);

    // Умножаем n * (n + 1) * (2n + 1)
    string part1 = multiply_large_numbers(n_str, n_plus_1);
   string part2 = multiply_large_numbers(part1, two_n_plus_1);

    // Разделим результат на 6
    return divide_large_number_by_6(part2);
}

// Проверка на корректность ввода
bool is_valid_input(string& n) {
    // Пустой ввод
    if (n.empty()) {
       cout << "Ошибка: Введена пустая строка!" << endl;
        return false;
    }

    // Проверка на отрицательные числа
    if (n[0] == '-') {
        cout << "Ошибка: Отрицательные числа не поддерживаются!" <<endl;
        return false;
    }

    // Проверка на наличие нецифровых символов
    for (char c : n) {
        if (!isdigit(c)) {
           cout << "Ошибка: Введено недопустимое значение! Введите число." << endl;
            return false;
        }
    }

    // Проверка на значение меньше 20000
    if (n.length() < 5 || (n.length() == 5 && n < "20000")) {
       cout << "Ошибка: Число должно быть не меньше 20000!" << endl;
        return false;
    }

    return true;
}
