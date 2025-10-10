#include <iostream>
#include "../include/four.h"

using namespace std;
int main() {
    Four a("132");
    Four b("203");

    // сравнения
    if (Four::greater(a, b))
        cout << "a > b" << "\n";
    else if (Four::less(a, b))
        cout << "a < b" << "\n";
    else
        cout << "a == b" << "\n";

    // сложение
    Four sum = Four::add4(a, b);
    cout << "a + b = " << sum.to_string() << "\n"; 

    // вычитание с try catch
    try {
        Four diff = Four::sub4(a, b);
        cout << "a - b = " << diff.to_string() << "\n";
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
