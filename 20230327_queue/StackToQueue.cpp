//用两个栈实现队列push 和 pop
#include<iostream>
#include<stack>
using namespace std;

void Push(stack<int>* s1,stack<int>* s2,int num){
    while(!(s2->empty())){
        int temp=s2->top();
        s1->push(temp);
        s2->pop();
    }
    s1->push(num);
}

void Pop(stack<int>* s1,stack<int>* s2){
    while(!(s1->empty())){
        int temp=s1->top();
        s2->push(temp);
        s1->pop();
    }
    s2->pop();
}
int GetFront(stack<int>* s1,stack<int>* s2){
    while(!(s1->empty())){
        int temp=s1->top();
        s2->push(temp);
        s1->pop();
    }
    return (s2->top());
}

int main(){
    stack<int>* s1 = new stack<int>;
    stack<int>* s2 = new stack<int>;
    Push(s1, s2, 1);  
    Push(s1, s2, 2);
    Push(s1, s2, 3);
    Pop(s1, s2);
    Pop(s1, s2);
    Push(s1, s2, 4);
    // Pop(s1, s2);
    cout<<GetFront(s1,s2)<<endl;
}