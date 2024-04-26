/*
Этот код анализирует текст, разделенный на предложения, и извлекает уникальные слова из предложений, которые заканчиваются точкой (‘.’).
Затем он выводит эти слова, если они не встречаются в предложениях, заканчивающихся восклицательным знаком (‘!’) или вопросительным знаком (‘?’).
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string word = "";
    set<string> exclamatorySentences, fullStopSentences, uniqueWords;
    string text = "VecTor set mAiN algorithm! veCtor sEt AlgoRithm iosTreAm. string nAmeSpace VeCTor SeT alGoriThM?";
    string delimiters = "!?.";

    auto it = text.begin();
    while (it != text.end()) {
        // Находим следующий знак препинания
        auto end = find_if(it, text.end(), [&delimiters](char c) { return delimiters.find(c) != string::npos; });
        // Обрабатываем слова в предложении до знака препинания
        for (auto i = it; i != end; ++i) {
            if (*i == ' ' || i == end - 1) {
                if (i == end - 1) {
                    word += *i;
                }
                // Выбираем множество для добавления слова в зависимости от знака препинания
                set<string>& target = (*end == '.' ? fullStopSentences : exclamatorySentences);
                target.insert(word);
                word.clear();
            }
            else {
                word += tolower(*i);
            }
        }
        // Переходим к следующему предложению
        it = end != text.end() ? end + 1 : text.end();
    }

    // Вычисляем разницу между множествами и сохраняем результат в векторе
    vector<string> result(fullStopSentences.size());
    set_difference(fullStopSentences.begin(), fullStopSentences.end(), exclamatorySentences.begin(), exclamatorySentences.end(), result.begin());

    // Выводим результат
    for (const auto& word : result) {
        cout << word << " ";
    }
    cout << endl;

    // Приостанавливаем выполнение программы
    system("pause");
}
