#include <iostream>
using namespace std;
int main()
{int n=5;
  int s=n/2;

  int star=1,k=s;
  for (int j = 1; j <= n; j++)
  {
    /* code */
    for (int i = 0; i < s; i++)
    {
      /* code */
      cout<<"# ";

    }
         for (int i = 0; i < star; i++)
    {
      /* code */
      if (j<=(n/2)+1)
    {
      cout<<j;
    }
    else{
      cout<<n-j+1;
   
      
    }
    }
     cout<<endl;
    if (j<=n/2)
    {
    
      s--;
      star+=2;
    }
    else{
    
      s++;
      star-=2;
    }
   
  }
  
}