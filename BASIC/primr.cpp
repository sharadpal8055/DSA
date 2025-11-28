#include <iostream>
using namespace std;
int main()
{
    int n,arr[100],
    t, flag = 0;
cout << "how many numbers";
cin >> t;
for (int i = 0; i < t; i++)
{
  cout<<i+1 << "number";
  cin >> arr[i];
  for (int j = 2; j < arr[i]/ 2 + 1; j++)
  {
    if (arr[i] % j == 0)
    {
      flag++;
    }
  }

if (flag != 0)
{
  cout<<arr[i] << "number is not  prime" << n << endl;
}
else
{
  cout<<arr[i] << "number is  prime";
}
}
}
