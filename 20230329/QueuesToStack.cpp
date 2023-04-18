#include<iostream>
#include<queue>
using namespace std;

void Push(queue<int> &q1,queue<int> &q2,int value){
    //入非空的里面
    if(!q1.empty()){
        q1.push(value);
    }
    else{
        q2.push(value);
    }
}

void Pop(queue<int> &q1,queue<int> &q2){
    if(q1.empty()&&q2.empty())
        return;
    int temp;
    if (!q1.empty())
    {   
        //除尾元素外，其余元素均入另一个队列
        while(q1.size() > 1){
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        //弹出剩余元素
        temp = q1.front();
        q1.pop();
        cout << temp << endl;
    }
    else{
        //除尾元素外，其余元素均入另一个队列
        while(q2.size() > 1){
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        //弹出剩余元素
        temp = q2.front();
        q2.pop();
        cout << temp << endl;
    }
}

int main(){
    queue<int> q1;
    queue<int> q2;
    Push(q1,q2,1);
    Push(q1,q2,2);
    Push(q1,q2,3);
    Push(q1,q2,4);
    Pop(q1,q2);
    Pop(q1,q2);
    return 0;
}