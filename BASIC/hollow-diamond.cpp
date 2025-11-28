#include <iostream>
using namespace std;
int main()
{ int n=7;
  int os=n/2;
   int is=-1;
  for (int i = 0; i < n; i++)
  {
    /* code */
    //for outerspace
    for (int i = 0; i <os; i++)
    {
      /* code */
      cout<<"#";
    }
    os--;
    //star
     
      cout<<"*";
       for (int i = 0; i <is; i++)
    {
      /* code */
      if (i>=0)
      {cout<<"#";
        /* code */
      }
      else break;
      
    }
    is+=2;
    cout<<"*";
    cout<<endl;
  }
  
}