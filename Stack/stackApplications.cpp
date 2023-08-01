#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c== '/') return 2;
    else if(c == '+' || c== '-') return 1;
    else return -1; 
}

void infixToPostfix(string s){
    stack <char> st;
    string result = "";
    for(int i=0;i<s.length();i++){
        char c = s[i];
        
        // if c is operand then print directly
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) result += c;
        else if(c == '(') st.push(c); // push open bracket
        else if(c == ')'){
            // if c== ')' then pop all elements in stack until '(' is encountered
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{ // if operator is encountered
            while(!st.empty() && prec(c) <= prec(st.top())){
                if(c == '^' && st.top() != '^') break;
                else{
                    result+= st.top();
                    st.pop();
                }
            }
            st.push(c);
        }        
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int evalPostfix(string s){
    int res =0;
    stack<int> st;

    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if(c >='0' && c <='9') st.push((int)c-48);
        else{
             int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
            
            switch(c){
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(b-a);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(b/a);
                    break;
            }
        }
    }
    return st.top();
}

void reverseString(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }

    string reversed = "";
    for(int i=0; i<s.length(); i++){
        reversed+=st.top();
        st.pop();
    }
    cout<< reversed<< endl;

}

bool checkBalancedParenthesis(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(st.empty()) st.push(s[i]);
        else if((st.top()=='(' && s[i] == ')') || (st.top()=='{' && s[i] == '}')  || (st.top()=='[' && s[i] == ']'))
        st.pop();
        else st.push(s[i]);

        
    }
    if(st.empty()) return true;
    return false;
}

void printNGE(int arr[], int n){
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<n; i++){
        int next = arr[i];
        while(!st.empty() &&  next >= st.top()){
            cout << st.top() << "->" << next << endl;
            st.pop();
        }
        st.push(next);
    }
    while(!st.empty()){
        cout << st.top() << "->" << "-1" << endl;
        st.pop();
    }
}

void sortedInsert(stack<int> st, int el){
    if(st.empty() || el >= st.top()) st.push(el);
    else{
        int temp = st.top();
        sortedInsert(st, el);
        st.push(el);
    }
}

void sortStack(stack<int>& st){
    if(!st.empty()){
        int temp = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, temp);
    }
}

void stockSpan(int prices[], int n){
    int span[n];
    stack<int> st;
    span[0] =1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && prices[st.top()] <= prices[i]){
            st.pop();
        }

        span[i] = (st.empty()) ? (i+1) : (i-st.top());
        st.push(i); 
    }

    for(int i=0; i<n;i++){
        cout << span[i] << " ";
    }
    cout << endl;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);

    string exp2 = "231*+9-"; 
     cout << evalPostfix(exp2) << endl;
    
    string name = "gowtham";
    reverseString(name);

    string expr = "{()}[]";
    cout << checkBalancedParenthesis(expr) << endl;

    int arr[4] = {11,13,21,3};
    printNGE(arr, 4);

    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    stockSpan(price,n );
    return 0;
}