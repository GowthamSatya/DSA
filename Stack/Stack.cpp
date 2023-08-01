#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    vector<int> stack;

    bool isEmpty(){
        if(top == -1) return true;
        return false;
    }

    public:
    Stack(){
        top = -1;
    }

    void push(int item){
        top++;
        stack.push_back(item);
      
    }

    int pop(){
        if(isEmpty()){
            cout<< "Stack Underflow"<< endl;
            return -1;
        }
        return stack[top--];
    }

    int size(){
        return stack.size();
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    void peek(){
        cout << stack[top] << endl;
    }

};

int main(){
    Stack s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(7);
    int last = s.pop();

    cout << last << endl;
    s.peek();
    s.display();
    return 0;
}