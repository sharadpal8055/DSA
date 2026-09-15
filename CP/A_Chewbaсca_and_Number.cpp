#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';

        // First digit cannot become 0.
        if (i == 0 && digit == 9)
            continue;

        digit = min(digit, 9 - digit);
        s[i] = digit + '0';
    }

    cout << s << '\n';

    return 0;
}