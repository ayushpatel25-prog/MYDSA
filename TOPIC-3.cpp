// ArrayImplimentationOf-Queue
// HERE WE ARE WASTING A LOT OF SPACE IN AN ARRAY AND ALSO WE CANT PUSH
// EXAMPLE 1 2 3 4 5 6
//wastspace|<->| f   b
// Queue size    |<-->|
// SOLUTION IS CIRCULAR ARRAY
#include<iostream>
#include<queue>
using namespace std;
class Queue{
public:
    int f;
    int b;
    int arr[5];
    Queue(){
        f=0;
        b=0;
    }
    void push(int val){
        if(b==5){
            cout<<"Queue is full"<<" "<<endl;
            return;
        }
        arr[b]=val;
        b++;

    }
    void pop(){
        if(f-b==0){
            cout<<"Queue is empty";
            return;
        }
        f++;
    }
    int front(){
         if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];

    }
    int back(){
         if(f-b==0){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(f-b==0) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
     q.push(60);
         q.display();
    q.pop();
     q.display();

}