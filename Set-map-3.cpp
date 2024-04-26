/*
Этот код анализирует текст из файла, подсчитывает количество вхождений каждого слова и числа, и выводит те слова, которые встречаются в тексте столько же раз, сколько и первое число.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    // Устанавливаем локаль для корректной работы с русским языком
    setlocale(LC_ALL, "Russian");

    string str;
    string filePath;

    // Запрашиваем у пользователя путь к файлу
    cout << "Введите путь к файлу: ";
    getline(cin, filePath);

    // Пытаемся открыть файл
    ifstream fin(filePath);
    if (!fin) {
        // Если файл не удалось открыть, выводим сообщение об ошибке
        cout << "Не удалось открыть файл. Проверьте путь к файлу и попробуйте снова." << endl;
        return 1;  // Завершаем программу с кодом ошибки 1
    }

    string word, first_num;
    map<string, int> words, numbers;

    // Считываем строку из файла
    getline(fin, str);

    // Итератор для прохода по строке
    auto it = str.begin();
    while (it != str.end()) {
        // Находим следующий пробел или конец строки
        auto end = find(it, str.end(), ' ');
        // Формируем слово из символов между it и end
        word.assign(it, end);
        // Если слово содержит цифры, добавляем его в map numbers, иначе в map words
        (any_of(word.begin(), word.end(), ::isdigit) ? numbers : words)[word]++;
        // Если это первое число, запоминаем его
        if (numbers[word] == 1 && first_num.empty()) {
            first_num = word;
        }
        // Переходим к следующему слову
        it = end != str.end() ? end + 1 : str.end();
    }

    // Выводим слова, которые встречаются столько же раз, сколько и первое число
    for (const auto& [word, count] : words) {
        if (count == numbers[first_num]) {
            cout << word << endl;
        }
    }

    // Приостанавливаем выполнение программы
    system("pause");
}
