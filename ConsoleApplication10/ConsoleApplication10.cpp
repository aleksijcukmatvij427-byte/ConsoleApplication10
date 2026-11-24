#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    int ToSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:

    // Конструктор за замовчуванням
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Конструктор (hours, minutes, seconds)
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Конструктор (seconds)
    explicit Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds / 60) % 60;
        seconds = totalSeconds % 60;
    }

    // Виведення часу
    void Show() const {
        cout << setfill('0')
            << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    // ++ (збільшення на 1 секунду)
    Time operator++(int) {
        Time temp = *this;

        seconds++;

        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }

        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }

        return temp;
    }

    // +
    Time operator+(const Time& other) const {
        return Time(ToSeconds() + other.ToSeconds());
    }

    // -
    Time operator-(const Time& other) const {
        int result = ToSeconds() - other.ToSeconds();

        if (result < 0)
            result = 0;

        return Time(result);
    }

    // *
    Time operator*(const Time& other) const {
        return Time(ToSeconds() * other.ToSeconds());
    }

    // /
    Time operator/(const Time& other) const {
        if (other.ToSeconds() == 0)
            return Time();

        return Time(ToSeconds() / other.ToSeconds());
    }

    // >
    bool operator>(const Time& other) const {
        return ToSeconds() > other.ToSeconds();
    }

    // <
    bool operator<(const Time& other) const {
        return ToSeconds() < other.ToSeconds();
    }

    // >=
    bool operator>=(const Time& other) const {
        return ToSeconds() >= other.ToSeconds();
    }

    // <=
    bool operator<=(const Time& other) const {
        return ToSeconds() <= other.ToSeconds();
    }

    // ==
    bool operator==(const Time& other) const {
        return ToSeconds() == other.ToSeconds();
    }

    // !=
    bool operator!=(const Time& other) const {
        return ToSeconds() != other.ToSeconds();
    }
};

int main() {

    Time t1(1, 20, 30);
    Time t2(0, 40, 15);

    cout << "t1 = ";
    t1.Show();

    cout << "t2 = ";
    t2.Show();

    cout << "\nОператор +" << endl;
    Time t3 = t1 + t2;
    t3.Show();

    cout << "\nОператор -" << endl;
    Time t4 = t1 - t2;
    t4.Show();

    cout << "\nОператор *" << endl;
    Time t5 = t1 * t2;
    t5.Show();

    cout << "\nОператор /" << endl;
    Time t6 = t1 / t2;
    t6.Show();

    cout << "\nПорівняння:" << endl;

    if (t1 > t2)
        cout << "t1 > t2" << endl;

    if (t1 >= t2)
        cout << "t1 >= t2" << endl;

    if (t2 < t1)
        cout << "t2 < t1" << endl;

    if (t2 <= t1)
        cout << "t2 <= t1" << endl;

    if (t1 != t2)
        cout << "t1 != t2" << endl;

    cout << "\nЗбільшення на 1 секунду:" << endl;

    Time t7(11, 59, 59);

    t7.Show();

    t7++;

    t7.Show();

    cout << "\nКонструктор із секунд:" << endl;

    Time t8(5555);

    t8.Show();

    return 0;
}