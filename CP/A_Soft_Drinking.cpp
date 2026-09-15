#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,l,c,d,p,nl,np;
  cin>>n>>k>>l>>c>>d>>p>>nl>>np;
 int ans=0;
 int r1=k*l/nl;
 int r2=c*d;
 int r3=p/np;
  ans=min({r1,r2,r3});
  cout<<ans/n;
  return 0;
}