// REVERSE FIRST K ELEMENTS FROM THE QUEUE
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

    cout << "Queue: ";
    for(int i=0;i<n;i++){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        q.push(y);
    }
    cout<<endl;
    

    int k;
    cout<<"value of k";
    cin>>k;

    for(int i=0;i<k;i++){
        int z=q.front();
        s.push(z);
        q.pop();
    }
    for(int i=0;i<k;i++){
        int m=s.top();
        q.push(m);
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        int m=q.front();
        q.pop();
        q.push(m);

    }
    cout << "Queue: ";
    for(int i=0;i<n;i++){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        q.push(y);
    }



}