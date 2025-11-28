#include <iostream>
using namespace std;

int main() {
int n=7;
for (int i = 1; i <= n; i++)
{
  for (int j = 1; j <= n; j++)
{
  /* code */
  if(i==n/2 +1||j==n/2+1||i==1||j==1||i==n||j==n){
    cout<<"*\t";
  }
  
    
      else 
      {
  cout<<"\t";
      }
} 
  /* code */
  cout<<"\t"<<endl;
}


}