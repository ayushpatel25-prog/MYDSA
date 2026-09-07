#include<iostream>
#include<stack>
using namespace std;
int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}
int solve(int a,int b,char ch){
    if(ch=='+') return (a+b);
    else if(ch=='-') return (a-b);
    else if(ch=='*') return (a*b);
    else return (a/b);

}
int main(){
    string s="2+6*4/8-3";//infix expression
    // we need two stacks one for value and one for operators
    stack<int>val;
    stack<char>op;
    for(int i=0;i<s.length();i++){
        // check if s[i] is digit?
        if(s[i]>=48 && s[i]<=57){
            val.push(s[i]-48);
        }
        else{ //s[i] it is->*,/,+,-;
            if(op.size()==0 || prio(s[i])>prio(op.top())){
                 op.push(s[i]); }
            else {//work 
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    int a2=val.top();
                    val.pop();
                    int a1=val.top();
                    val.pop();
                    char ch=op.top();
                    op.pop();
                    int ans=solve(a1,a2,ch);
                    val.push(ans);
                }
                op.push(s[i]);


            }
        }
         
    }
     while(op.size()>0){
                    int a2=val.top();
                    val.pop();
                    int a1=val.top();
                    val.pop();
                    char ch=op.top();
                    op.pop();
                    int ans=solve(a1,a2,ch);
                    val.push(ans);
                }
                cout<<val.top();
    

}