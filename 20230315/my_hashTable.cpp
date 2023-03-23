#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef struct Node
{
    int value;
    struct Node *Next;
    Node():value(0),Next(nullptr){}
    Node(int x):value(x),Next(nullptr){}
}List;

List ** hashtablecreate(int n,int M){
    List **arr = new List*[n];
    //初始化：
    memset(arr, 0, sizeof(List *) * n);
    // for (int i = 0; i < n;i++){
    //     arr[i] = nullptr;
    // }
    int tmp;
    int index;
    List *P;
    for (int i = 0; i < n;i++){
        cout << "请输入数字：" << endl;
        cin >> tmp;
        if(arr[index=tmp % M]== nullptr){
            List* newnode = new List(tmp);
            arr[index]= newnode;
        }
        else{
            P = arr[index = tmp % M];
            while(P->Next){
                P = P->Next;
            }
            List* newnode = new List(tmp);
            P->Next = newnode;
        }
    }
    return arr;
}

void search_hash(int target ,List ** Hash, int M){
    int index = target % M;
    List *pTemp = Hash[index];
    while(pTemp){
        if(pTemp->value == target){
            cout << "找到 " << pTemp->value << endl;
            cout << "index:"<<index << endl;
            return;
        }
        pTemp = pTemp->Next;
    }
    cout << "failed" << endl;
}

//申请数组
int main(){
    int len;
    int M ;
    cout << "请输入你输入的个数" << endl;
    cin>>len;
    M = len;
    List **Hash = hashtablecreate(len, M);
    cout << "请输入你要查找的数字" << endl;
    int target;
    cin >> target;
    search_hash(target, Hash, M);
    cout << "请输入你要查找的数字" << endl;
    cin >> target;
    search_hash(target, Hash, M);
}