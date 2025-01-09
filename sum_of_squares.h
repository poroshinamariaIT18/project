#pragma once
#ifndef SUM_OF_SQUARES_H
#define SUM_OF_SQUARES_H
#include <string>
using namespace std;

// Функция для преобразования числа в строку
string to_str(long long int m);

// Умножение больших чисел, представленных строками
string multiply_large_numbers(string a, string b);

// Деление больших чисел на 6
string divide_large_number_by_6(string n);

// Функция для вычисления суммы квадратов от 1 до n
string sum_of_squares(string n_str);

// Проверка на корректность ввода
bool is_valid_input(string& n);

#endif
