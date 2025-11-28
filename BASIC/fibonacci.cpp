#include <iostream>
using namespace std;
int main()
{ int n=10,i;
  int arr[100];
  arr[0]=0;
  arr[1]=1;
  cout<<" "<<  arr[0]<<" "<<  arr[1];
  for(i=2;i<n-1;i++){
    arr[i]=arr[i-1]+arr[i-2];
cout<<" "<<  arr[i]  ;
  }

}