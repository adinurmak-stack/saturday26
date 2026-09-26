#include <iostream>
#include <limits>

using namespace std;

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите целое число.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

void runControlQuestions() {
    cout << "\n--- Контрольные вопросы ---\n";
    int score = 0;

    int a1 = readInt("Сколько байт занимает тип int (обычно)? ");
    if (a1 == 4) score++;

    int a2 = readInt("Индексация массивов в C++ начинается с 0 или 1? (введите 0 или 1) ");
    if (a2 == 0) score++;

    cout << "Правильных ответов: " << score << " из 2\n";
}

void showMainMenu() {
    cout << "\n===== ГЛАВНОЕ МЕНЮ =====\n";
    cout << "1. Контрольные вопросы\n";
    cout << "0. Выход\n";
}

int main() {
    bool running = true;

    while (running) {
        showMainMenu();
        int choice = readInt("Выберите пункт меню: ");

        switch (choice) {
            case 1:
                runControlQuestions();
                break;
            case 0:
                running = false;
                cout << "Завершение работы бота.\n";
                break;
            default:
                cout << "Неверный пункт меню, попробуйте снова.\n";
        }
    }

    return 0;
}
