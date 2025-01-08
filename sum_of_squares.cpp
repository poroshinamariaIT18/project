#include "sum_of_squares.h"
#include <iostream>
#include <string> // ��� ������ �� ��������
#include <cstdlib> // ��� ������ � ��������� ���������, �������� �������������� ������ � �����
#include <cmath>// ��� ������ � ��������������� ���������
using namespace std;
// ������� ��� �������������� ����� � ������
string to_str(long long int m) {
	return to_string(m); 
}
// ��������� ������� �����, �������������� ��������
string multiply_large_numbers(string a, string b) {
    int len_a = a.length();
	int len_b = b.length(); // ����� ����� a � b 
	int result_len = len_a + len_b;  // ����� �������������� ������ ����� ����� ���� a � b
	int* result = new int[result_len](); // ������������ ������ ��� �������� ���������� ���������
   //��� ��������� �����, ������� �������� �� ���� ������ ����� � ������� � � b ������� � ������� ��������
    for (int i = len_a - 1; i >= 0; --i) { 
        for (int j = len_b - 1; j >= 0; --j) { 
            int mul = (a[i] - '0') * (b[j] - '0');// ����������� ����� �� ����� 
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;// ������� ����� ���-�� � ���.�������
			result[i + j] += sum / 10;// ������� ����� ���-�� � ���������� �������
        }
    }

    // ����������� ��������� � ������,�������� �� ������� ������� ������ ���-�� ��������� ������� ����
    string result_str = "";
    for (int i = 0; i < result_len; ++i) {
        if (!(result_str.empty() && result[i] == 0)) {
            result_str += (result[i] + '0');
        }
    }
    delete[] result;
    return result_str.empty() ? "0" : result_str;
}

// ������� ������� ����� �� 6
string divide_large_number_by_6(string n) {
    int remainder = 0;
    string result = "";

    for (char c : n) {
        int current = remainder * 10 + (c - '0');
        result += (current / 6) + '0';
        remainder = current % 6;
    }

    // ������� ������� ����
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

// ������� ��� ���������� ����� ��������� �� 1 �� n  �� �������
string sum_of_squares(string n_str) {
    string n_plus_1 = to_str(stoi(n_str) + 1);
    string two_n_plus_1 = to_str(2 * stoi(n_str) + 1);

    // �������� n * (n + 1) * (2n + 1)
    string part1 = multiply_large_numbers(n_str, n_plus_1);
   string part2 = multiply_large_numbers(part1, two_n_plus_1);

    // �������� ��������� �� 6
    return divide_large_number_by_6(part2);
}

// �������� �� ������������ �����
bool is_valid_input(string& n) {
    // ������ ����
    if (n.empty()) {
       cout << "������: ������� ������ ������!" << endl;
        return false;
    }

    // �������� �� ������������� �����
    if (n[0] == '-') {
        cout << "������: ������������� ����� �� ��������������!" <<endl;
        return false;
    }

    // �������� �� ������� ���������� ��������
    for (char c : n) {
        if (!isdigit(c)) {
           cout << "������: ������� ������������ ��������! ������� �����." << endl;
            return false;
        }
    }

    // �������� �� �������� ������ 20000
    if (n.length() < 5 || (n.length() == 5 && n < "20000")) {
       cout << "������: ����� ������ ���� �� ������ 20000!" << endl;
        return false;
    }

    return true;
}
