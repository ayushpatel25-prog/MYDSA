// REORDER QUEUE (INTERLEAVE 1ST HALF AND 2ND HALF)
// [DO THIS BY USING ONE STACK ONLY]
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
     queue<int>q;
    stack<int>s;
    //  FOR INPUT IN QUEUE IN LOOP
    int n;
    cout << "Kitne elements dalne hain: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cout << "Element enter karo: ";
        cin >> x;

        q.push(x);
    }
    for(int i=0;i<n;i++){
        if(i<n/2){
            s.push(q.front());
            q.pop();
        }
    }
    while(s.size()!=0){
        q.push(s.top());
        s.pop();
    }
    

    for(int i=0;i<n/2;i++){
            s.push(q.front());
            q.pop();
        }
    
     cout << "Queue: ";
    for(int i=0;i<q.size();i++){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        q.push(y);
    }
    cout<<endl;

    while(s.size()!=0){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    cout << "Queue: ";
    for(int i=0;i<n;i++){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        q.push(y);
    }
    cout<<endl;

    

}