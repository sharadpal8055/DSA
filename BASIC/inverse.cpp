#include <iostream>
using namespace std;
int main()
{
  int arr[5],rarr[5],res[5];
  int i=0,r=0,k=0;
int n=4213;
for( i=0;i<4;i++){
arr[i]=n%10;
n=n/10;
}
for( i=0;i<4;i++){
//cout<<arr[i];
}
for( i=1;i<=4;i++){
  rarr[arr[i-1]-1]=i;

}
for( i=0;i<4;i++){
 //cout<<" "<<rarr[i];
}
for( i=0;i<4;i++){
 res[i]=rarr[3-i];
}
for( i=0;i<4;i++){
 cout<<" "<<res[i];
}

}