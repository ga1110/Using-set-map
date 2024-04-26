/*
 Этот код выполняет задачу сортировки и фильтрации цифр из введенных пользователем чисел.
 Он разделяет цифры чисел, которые находятся в диапазоне от 10 до 100, и цифры чисел, которые находятся вне этого диапазона, на два разных множества.
 Затем он выводит только те цифры из первого множества, которых нет во втором множестве.
*/
#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <string_view>

using namespace std;

int main()
{
    int n, t;
    set<int> a, b, c;

    // Запрашиваем у пользователя число n
    cout << "n = ";
    cin >> n;

    // Запрашиваем у пользователя n чисел и добавляем их в множество a
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> t;
        a.insert(t);
    }

    // Выводим все числа из множества a
    for (const auto& element : a) {
        cout << element << " ";
    }
    cout << endl;

    // Разделяем цифры чисел на два множества в зависимости от их диапазона
    for (const auto& element : a) {
        set<int>& target = (element >= 10 && element <= 100) ? b : c;
        t = element;
        while (t > 0) {
            target.insert(t % 10); // Добавляем цифры числа в соответствующее множество
            t /= 10;
        }
    }

    // Очищаем множество a
    a.clear();
    cout << endl;

    // Добавляем в множество a только те цифры из множества b, которых нет в множестве c
    for (const auto& element : b) {
        if (c.count(element) == 0) {
            a.insert(element);
        }
    }

    // Выводим все числа из множества a
    for (const auto& element : a) {
        cout << element << " ";
    }
    cout << endl;

    // Приостанавливаем выполнение программы, ожидая нажатия любой клавиши
    system("pause");
}