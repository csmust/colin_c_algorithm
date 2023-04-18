#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int nValue;
    struct node *pLeft;
    struct node *pRight;
} BinaryTree;

// BinaryTree *CreateBinaryTree(){
//     BinaryTree *pRoot = NULL;
//     //根
//     pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
//     pRoot->nValue = 1;

//     //左孩子
//     pRoot->pLeft = (BinaryTree *)malloc(sizeof (BinaryTree));
//     pRoot->pLeft->nValue = 2;

//     //左孩子的左孩子
//     pRoot->pLeft->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
//     pRoot->pLeft->pLeft->nValue = 4;
//     pRoot->pLeft->pLeft->pLeft = NULL;
//     pRoot->pLeft->pLeft->pRight = NULL;
//     //左孩子的右孩子
//     pRoot->pLeft->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
//     pRoot->pLeft->pRight->nValue = 5;
//     pRoot->pLeft->pRight->pLeft = NULL;
//     pRoot->pLeft->pRight->pRight = NULL;
//     //右孩子
//     pRoot->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
//     pRoot->pRight->nValue = 3;
//     pRoot->pRight->pLeft = NULL;
//     pRoot->pRight->pRight = NULL;

//     return pRoot;
// }
void CreateBinaryTree(BinaryTree **pTree){
    int nValue;
    scanf("%d", &nValue);
    if (nValue == 0){
        *pTree = NULL;
    }else{
        *pTree = (BinaryTree *)malloc(sizeof(BinaryTree));
        (*pTree)->nValue = nValue;
        CreateBinaryTree(&((*pTree)->pLeft));
        CreateBinaryTree(&((*pTree)->pRight));
    }
}

void PreOrder(BinaryTree *pTree)
{
    if (!pTree)
        return;
    printf("%d ", pTree->nValue);
    PreOrder(pTree->pLeft);
    PreOrder(pTree->pRight);
}
//中序遍历
void InOrder(BinaryTree *pTree)
{
    if (!pTree)
        return;
    InOrder(pTree->pLeft);
    printf("%d ", pTree->nValue);
    InOrder(pTree->pRight);
}
//后序遍历
void PostOrder(BinaryTree *pTree)
{
    if (!pTree)
        return;
    PostOrder(pTree->pLeft);
    PostOrder(pTree->pRight);
    printf("%d ", pTree->nValue);
}

BinaryTree *CreatCBT(int arr[],int nlen)
{
    if(arr == NULL || nlen == 0 )
        return NULL;
    //节点数组
    BinaryTree *pTree = NULL;
    pTree = (BinaryTree *)malloc(sizeof(BinaryTree) * nlen);

    //值赋值
    int i;
    for (i = 0; i < nlen;i++)
    {
        pTree[i].nValue=arr[i];
        pTree[i].pLeft = NULL;
        pTree[i].pRight = NULL;
    }

    //左右关联
    for (i = 0; i <= nlen / 2 - 1;i++){
        if(2*i+1<=nlen-1)
        {
            pTree[i].pLeft = &pTree[2 * i + 1];
        }
        if(2*i+2<=nlen-1)
        {
            pTree[i].pRight = &pTree[2 * i + 2];
        }
    }
    return pTree;
}


int main(){
    BinaryTree *pRoot = NULL;
    // CreateBinaryTree(&pRoot);
    int arr[] = {1,2,3,4,5};
    pRoot = CreatCBT(arr, sizeof(arr) / sizeof(arr[0]));
    PreOrder(pRoot);
    // InOrder(pRoot);
    // PostOrder(pRoot);
    printf("\n");
    return 0;
}