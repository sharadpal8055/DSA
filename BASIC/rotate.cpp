#include <iostream>
using namespace std;

int main() {
    int n = 23569;
    int r = 2;
    int temp = n;
    int count = 0;

    // Count digits
    while (temp > 0) {
        temp /= 10;
        count++;
    }

    int div = 1;
    for (int i = 0; i < r; i++) div *= 10;

    int last = n % div;        // last r digits
    int first = n / div;       // remaining part

    int mul = 1;
    for (int i = 0; i < count - r; i++) mul *= 10;

    int rotated = last * mul + first;

    cout << "Rotated number = " << rotated;
    return 0;
}
