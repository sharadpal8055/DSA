#include <iostream>
using namespace std;
int main()
{
  int n = 5,i,j;
  int space = 1;
  int star=n/2 +1;
  for ( i = 1; i <= n; i++)
  {
    
      for (int k = 1; k <= star; k++)
      {
        cout << "* ";
      }
      
      for (int m = 1; m <= space; m++)
      {
        /* code */
        cout << "  ";
      }
   
    
      for (int a = 1;a<= star;a++)
      {
        cout << "* ";
      }
      if(i<=n/2)
        { space+=2;
      star--;}
      else{
        space-=2;
      star++;
      }
       cout<<endl;
    
   
  }
    cout<<endl;
  return 0;
}