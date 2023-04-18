//非递归
#include<stdio.h>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct node{
    int nValue;
    struct node *pLeft;
    struct node *pRight;
} BinaryTree;

BinaryTree *CreateBinaryTree(){
    /*
          1
    2             3
4      5      null   null
    
    */
    BinaryTree *pRoot = NULL;
    //根
    pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->nValue = 1;

    //左孩子
    pRoot->pLeft = (BinaryTree *)malloc(sizeof (BinaryTree));
    pRoot->pLeft->nValue = 2;

    //左孩子的左孩子
    pRoot->pLeft->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pLeft->nValue = 4;
    pRoot->pLeft->pLeft->pLeft = NULL;
    pRoot->pLeft->pLeft->pRight = NULL;
    //左孩子的右孩子
    pRoot->pLeft->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pRight->nValue = 5;
    pRoot->pLeft->pRight->pLeft = NULL;
    pRoot->pLeft->pRight->pRight = NULL;
    //右孩子
    pRoot->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->nValue = 3;
    pRoot->pRight->pLeft = NULL;
    pRoot->pRight->pRight = NULL;
    //右孩子的左孩子
    pRoot->pRight->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->pLeft->nValue = 6;
    pRoot->pRight->pLeft->pLeft = NULL;
    pRoot->pRight->pLeft->pRight = NULL;
    //右孩子的右孩子
    pRoot->pRight->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->pRight->nValue = 7;
    pRoot->pRight->pRight->pLeft = NULL;
    pRoot->pRight->pRight->pRight = NULL;


    //左孩子的左孩子的左孩子
    pRoot->pLeft->pLeft->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pLeft->pLeft->nValue = 8;
    pRoot->pLeft->pLeft->pLeft->pLeft = NULL;
    pRoot->pLeft->pLeft->pLeft->pRight = NULL;


    return pRoot;
}


void PreOrder(BinaryTree *pTree){
    if (pTree == NULL)
        return;
    //辅助栈
    stack<BinaryTree *> s;

    //遍历
    while(1)
    {
        //处理
        while(pTree)
        {
            //打印
            cout << pTree->nValue << " ";
            //保存
            s.push(pTree);
            //左子树
            pTree = pTree->pLeft;
        }

        if(s.empty())
            break;
        pTree = s.top();
        s.pop();
        //右子树
        pTree = pTree->pRight;
    }
    cout << endl;
}

void InOrder(BinaryTree *pTree)
{

}
void LastOrder(BinaryTree *pTree){
    if(pTree == NULL)
        return;
    //辅助栈
    stack<BinaryTree*> s;
    //遍历
    BinaryTree *pMark = nullptr;
    while(1)
    {
        //处理
        while(pTree)
        {
            s.push(pTree);
            //左子树
            pTree = pTree->pLeft;
        }
        if (s.empty())
            break;
        //检测栈顶元素的右子树
        if(s.top()->pRight == NULL || s.top() ->pRight == pMark)
        {
            //弹出 标记 打印
            pMark = s.top();   //记录上次弹出节点
            s.pop();
            cout << pMark->nValue << " ";
        }
        else{
            //右子树
            pTree = s.top()->pRight;
        }
    }
}
//层序遍历 分层打印
void LayerOrder(BinaryTree *pTree){
    if (pTree==NULL)
        return;
    int i = 0;
    int j = 1;
    queue<BinaryTree *> q;
    q.push(pTree);
    while(!q.empty()){
        // int pre = q.size();
        BinaryTree *temp = q.front();
        q.pop();
        cout << temp->nValue << " "; 
        i++;
        if (i == j)
        {
            if (temp->pLeft != NULL)
                q.push(temp->pLeft);
            if(temp->pRight!=NULL)
                q.push(temp->pRight);
            cout <<"一层"<<endl;   //打印回车的时候，队列里应该全是下一层
            i = 0;           
            j = q.size();
        }
        else{
            if (temp->pLeft != NULL)
                q.push(temp->pLeft);
            if(temp->pRight!=NULL)
                q.push(temp->pRight);
        }
    }
}

int main(){
    BinaryTree *pRoot = NULL;
    pRoot=CreateBinaryTree();

    // PreOrder(pRoot);
    // InOrder(pRoot);
    LastOrder(pRoot);
    printf("\n");
    LayerOrder(pRoot);
    printf("\n");

    return 0;
}