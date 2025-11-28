#include <iostream>
using namespace std;
int main()
{
  int n = 4, s = (2 * n) - 3, va;
  for (int i = 1; i <= n; i++)
  {
    for (int k = 1; k <= i; k++)
    {
      /* code */
      cout << k;
    }
    if (s > 0)
    {
      /* code */

      for (int k = 1; k <= s; k++)
      {
        /* code */
        cout << "# ";
      }
      s -= 2;
    }
     int l=i;
   if (i==n)
   {
      
  l--;
    /* code */
   }
  
   for (int k = 1; k <= l; k++)
    {
      /* code */
      cout << l - k + 1;
    }
    for (int j = 1; j <= (2 * n) - 1; j++)
      cout << endl;
    /* code */
  }
}
