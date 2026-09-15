#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;

  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
      string state;
      cin >> state;
      int plusop = 0;
      int minop = 0;
      for (int i = 0; i < state.length(); i++)
      {
        if (state[i] == '+')
          plusop++;
        else if (state[i] == '-')
          minop++;
      }
      if (plusop == 2)
        x++;
      else if (minop == 2)
        x--;
    }
    cout << x;
  }

  return 0;
}
