#include <iostream>
#include <limits>
#include <iomanip>

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

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Введите число.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

char readYesNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input == "y" || input == "Y") return 'y';
        if (input == "n" || input == "N") return 'n';
        cout << "Введите y или n.\n";
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

void workTimeModule() {
    cout << "\n--- Модуль 1: Учет рабочего времени ---\n";

    int daysPerWeek = readInt("Введите количество рабочих дней в неделе: ");
    double rate = readDouble("Введите ставку: ");

    double normHoursPerDay = 8.0 * rate;
    double hoursPerDay;
    bool confirmed = false;

    do {
        hoursPerDay = readDouble("Введите количество рабочих часов в день: ");
        double weeklyActual = hoursPerDay * daysPerWeek;
        double weeklyNorm = normHoursPerDay * daysPerWeek;

        if (hoursPerDay < normHoursPerDay) {
            double deficit = weeklyNorm - weeklyActual;
            double percent = (deficit / weeklyNorm) * 100.0;

            cout << fixed << setprecision(0);
            cout << "Ошибка! При " << daysPerWeek << "-дневной рабочей неделе "
                 << hoursPerDay << " часа в день составляют " << weeklyActual
                 << " часов в неделю. Дефицит рабочего времени: " << deficit
                 << " часов (" << percent << "% от нормы " << rate
                 << " ставки). Налицо факт предоставления заведомо ложных сведений работодателю.\n";
            confirmed = false;
        } else if (hoursPerDay == normHoursPerDay) {
            char answer = readYesNo("Подтвердите ввод нормы " + to_string((int)normHoursPerDay) + " часа(ов) в день (y/n): ");
            confirmed = (answer == 'y');
            if (!confirmed) cout << "Подтверждение не получено, ввод отклонен.\n";
        } else {
            cout << "Введенное значение превышает норму. Требуется ввести ровно "
                 << normHoursPerDay << " часа(ов) в день.\n";
            confirmed = false;
        }
    } while (!confirmed);

    cout << "Норма рабочего времени подтверждена. Модуль завершен.\n";
}

void showMainMenu() {
    cout << "\n===== ГЛАВНОЕ МЕНЮ =====\n";
    cout << "1. Контрольные вопросы\n";
    cout << "2. Учет рабочего времени\n";
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
            case 2:
                workTimeModule();
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
