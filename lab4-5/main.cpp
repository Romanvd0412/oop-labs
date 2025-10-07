#include <iostream>
#include <string>
using namespace std;

class Diode {
private:
    double forwardVoltage; // Пряма напруга (Вольт)
    double maxReverseCurrent; // Максимальний зворотний струм (мА)
    string purpose; // Призначення (наприклад, "rectifier", "zener")

public:
    // Конструктор за замовчуванням
    Diode() {
        forwardVoltage = 0.7; // Типове значення для кремнієвого діода
        maxReverseCurrent = 0.1; // Типове значення
        purpose = "unknown";
        cout << "Default constructor called!" << endl;
    }

    // Конструктор з параметрами
    Diode(double fv, double mrc, string pur) {
        if (fv >= 0.1 && fv <= 5.0) {
            forwardVoltage = fv;
        } else {
            forwardVoltage = 0.7;
            cout << "Error: Forward voltage must be between 0.1 and 5.0 V. Set to 0.7 V." << endl;
        }

        if (mrc >= 0.01 && mrc <= 10.0) {
            maxReverseCurrent = mrc;
        } else {
            maxReverseCurrent = 0.1;
            cout << "Error: Max reverse current must be between 0.01 and 10.0 mA. Set to 0.1 mA." << endl;
        }

        if (pur == "rectifier" || pur == "zener" || pur == "led") {
            purpose = pur;
        } else {
            purpose = "unknown";
            cout << "Error: Unknown purpose. Set to 'unknown'." << endl;
        }
        cout << "Parameterized constructor called!" << endl;
    }

    // Деструктор
    ~Diode() {
        cout << "Destructor called for diode with purpose: " << purpose << endl;
    }

    // Метод для встановлення прямої напруги
    void setForwardVoltage(double fv) {
        if (fv >= 0.1 && fv <= 5.0) {
            forwardVoltage = fv;
            cout << "Forward voltage set to: " << forwardVoltage << " V" << endl;
        } else {
            cout << "Error: Forward voltage must be between 0.1 and 5.0 V" << endl;
        }
    }

    // Метод для встановлення максимального зворотного струму
    void setMaxReverseCurrent(double mrc) {
        if (mrc >= 0.01 && mrc <= 10.0) {
            maxReverseCurrent = mrc;
            cout << "Max reverse current set to: " << maxReverseCurrent << " mA" << endl;
        } else {
            cout << "Error: Max reverse current must be between 0.01 and 10.0 mA" << endl;
        }
    }

    // Метод для встановлення призначення
    void setPurpose(string pur) {
        if (pur == "rectifier" || pur == "zener" || pur == "led") {
            purpose = pur;
            cout << "Purpose set to: " << purpose << endl;
        } else {
            cout << "Error: Allowed values: rectifier, zener, led" << endl;
        }
    }

    // Метод для виведення інформації про діод
    void displayInfo() {
        cout << "Diode: Forward voltage = " << forwardVoltage << " V, "
             << "Max reverse current = " << maxReverseCurrent << " mA, "
             << "Purpose = " << purpose << endl;
    }

    // Метод для перевірки призначення діода
    bool hasPurpose(string pur) {
        return purpose == pur;
    }
};

int main() {
    // Створення об’єктів класу
    Diode diode1; // Конструктор за замовчуванням
    diode1.displayInfo();

    Diode diode2(0.6, 0.05, "rectifier"); // Конструктор з параметрами
    diode2.displayInfo();

    Diode diode3(6.0, 15.0, "invalid"); // Некоректні параметри
    diode3.displayInfo();

    // Зміна значень полів diode1
    diode1.setForwardVoltage(0.8);
    diode1.setMaxReverseCurrent(0.2);
    diode1.setPurpose("zener");
    diode1.displayInfo();

    // Пошук діодів за призначенням
    cout << "\nSearching for diodes with purpose 'rectifier':" << endl;
    Diode* diodes[] = {&diode1, &diode2, &diode3}; // Масив вказівників для уникнення копіювання
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (diodes[i]->hasPurpose("rectifier")) {
            diodes[i]->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No diodes with purpose 'rectifier' found." << endl;
    }

    return 0;
}