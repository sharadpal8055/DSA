#include <iostream>
using namespace std;
#include <stack>


int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}
string rev(string s)
{stack<char> st;
  string revs;
  for (char c : s)
  {
    if(c == ' '){
      continue;
    }
   else if (c == '(')
    {
      st.push(')');
    }
    else if (c == ')')
    {
      st.push('(');
    }
    else
      st.push(c);
  }
  while (!st.empty())
  {
    revs += st.top();
    st.pop();
  }
  return revs;
}
string infixtopostfix(string s)
{stack<char> st2;
  string posts = "";
  for (char c : s)
  {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
      posts += c;
    }
    else if (c == '(')
    {
      st2.push(c);
    }
    else if (c == ')')
    {
      while (st2.top() != '(')
      {
        posts += st2.top();
        st2.pop();
      }
      st2.pop();
    }
    else if (c == '-' || c == '+' || c == '*' || c == '/' || c == '^')
    {
      while (!st2.empty() && (prec(st2.top()) > prec(c)||(prec(st2.top()) == prec(c)&&c!='^')))
      {
        posts += st2.top();
        st2.pop();
      }
      st2.push(c);
    }
   
  }
   while(!st2.empty()){
      posts += st2.top();
        st2.pop();
    }
  return posts;
}
int main()
{
  string s = "(A + B) - (C + D)";
  string revs = rev(s);
  string posts=infixtopostfix(revs);
  string pres=rev(posts);
  cout<<pres;
  //- + A B + C D

  return 0;
}