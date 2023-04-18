#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

typedef struct Node{
    int value;
    struct Node *pright;
    struct Node *pleft;
} BST;


void Addnode(BST** proot,int num)
{
    BST *pNode = *proot;
    
    BST *ptemp = NULL;
    ptemp = (BST *)malloc(sizeof(BST));
    ptemp->pleft = NULL;
    ptemp->pright = NULL;
    ptemp->value = num;

    if(*proot == NULL)
    {
        *proot = ptemp;
        return;
    }
    while (pNode)
    {
        if(num > (pNode->value))
        {
            if(pNode->pright == NULL){
                pNode->pright = ptemp;
                return;
            }
            pNode = pNode->pright;
        }
        else{
            if(pNode->pleft == NULL)
            {
                pNode->pleft = ptemp;
                return;
            }
            pNode = pNode->pleft;
        }
    }

}

void Search(BST *pTree , int nNum, BST **pDel, BST **pFather)
{
    if(pTree == NULL)
        return;
    while(pTree)
    {
        if(pTree->value == nNum)
        {
            *pDel = pTree;
            return;
        }
        else if(pTree->value > nNum)
        {
            //左子树
            *pFather = pTree;
            pTree = pTree->pleft;
        }
        else
        {
            //右子树
            *pFather = pTree;
            pTree = pTree->pright;
        }
    }
    *pFather = NULL;
}

// void Del(BST **proot,int num){
//     //search num
//     if(!proot)
//         return;
//     BST *pNode = *proot;
//     BST *pFather = NULL;
//     while (pNode)
//     {
//         if(pNode->value > num){
//             pFather = pNode;
//             pNode = pNode->pleft;
//         }
//         else if (pNode->value < num){
//             pFather = pNode;
//             pNode = pNode->pright;
//         }
//         else{
//             break;
//         }
//     }
//     if(!(pNode->pleft)  && !(pNode->pright)){
//         if(pFather->pleft==pNode)
//         {
//             pFather->pleft = NULL;
            
//             pNode = NULL;
//             delete pNode;
//         }        
//         else
//         {
//             pFather->pright = NULL;
            
//             pNode = NULL;
//             delete pNode;
//         }
//     }
// }

void DelNode(BST **pTree,int nNum)
{
    //查找
    BST *pDel = NULL;
    BST *pFather = NULL;
    Search(*pTree, nNum, &pDel, &pFather);
    //分析孩子节点情况
    //pDel有两个孩子
    BST *pMark = NULL;
    if(pDel->pleft !=NULL && pDel ->pright != NULL)
    {
        
        pMark = pDel;

        pFather = pDel;
        pDel = pDel->pleft;

        while(pDel->pright !=NULL)
        {
            pFather = pDel;
            pDel = pDel->pright;
        }

        //值覆盖
        pMark->value = pDel->value;  //pDel->value左子树最大值

        //此时，Del的right为空，有1个左孩子或0个孩子
    }

    //Del，有1个孩子或0个孩子
    //根
    if(pFather == NULL)
    {   //删的是根需要改变根
        *pTree = pDel->pleft ? pDel->pleft : pDel->pright;
        free(pDel);
        pDel = NULL;
        return;
    }
    //非根del是father左孩子
    if(pDel == pFather ->pleft)
    {
        pFather->pleft = pDel->pleft ? pDel->pleft : pDel->pright;  //del有左孩子的话,pFather->pleft=pDel->pleft 

    }
    //非根del是father右孩子
    else{
        pFather->pright = pDel->pleft ? pDel->pleft : pDel->pright;
    }
    free(pDel);
    pDel = NULL;
}

//中序遍历
void InOrder(BST *proot)
{
    if (proot == NULL)
        return;
    InOrder(proot->pleft);
    cout << proot->value << " ";
    InOrder(proot->pright);
}

BST* CreateBST(int arr[],int nlength)
{
    if(arr==NULL || nlength <=0)
        return NULL;
    BST *pRoot = NULL;
    int i;
    for (i = 0; i < nlength;i++)
    {
        Addnode(&pRoot, arr[i]);
    }
    return pRoot;
}

int main(){
    BST *proot = NULL;
    int arr[] = {10,2,9, 3, 7, 15, 16, 1, 14};
    int len = sizeof(arr) / sizeof(arr[0]);
    proot=CreateBST(arr, len);
    DelNode(&proot, 2);
    InOrder(proot);
    cout << endl;
    DelNode(&proot, 3);
    InOrder(proot);
}
