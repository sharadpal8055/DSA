#include <iostream>
#include<math.h>
using namespace std;
int main()
{
  int l, h, i, j;
  cout << "enter starting ";
  cin >> l;
  cout << "enter limit ";
  cin >> h;
  if(l==1) {
    l++;
  }

  for (i = l; i <= h; i++)
  {int flag=0;
    for (j = 2; j  <= sqrt(i); j++)
    {
      if (i % j == 0)
      {flag++;
        break;
      }
    }
    if(flag==0){
cout << i <<" ";
    }
  }
}