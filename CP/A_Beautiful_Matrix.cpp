#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ans = 0;
  int r1 = -1, c1 = -1;
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j <= 5; j++)
    {
      int x;
      cin >> x;
      if (x == 1)
      {
        r1 = i;
        c1 = j;
      }
    }
  }
  ans = abs(3 - r1) + abs(3 - c1);
  cout<<ans;
  return 0;
}
