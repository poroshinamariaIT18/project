#pragma once
#ifndef SUM_OF_SQUARES_H
#define SUM_OF_SQUARES_H
#include <string>
using namespace std;

// ������� ��� �������������� ����� � ������
string to_str(long long int m);

// ��������� ������� �����, �������������� ��������
string multiply_large_numbers(string a, string b);

// ������� ������� ����� �� 6
string divide_large_number_by_6(string n);

// ������� ��� ���������� ����� ��������� �� 1 �� n
string sum_of_squares(string n_str);

// �������� �� ������������ �����
bool is_valid_input(string& n);

#endif
