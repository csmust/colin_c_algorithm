#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int nValue;
    struct node *pLeft;
    struct node *pRight;
    struct node *pFather;
} BinaryTree;

//创建一个
BinaryTree *CreateBinaryTree(){
    BinaryTree *pRoot = NULL;
    //根
    pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->nValue = 1;
    pRoot->pFather = NULL;

    //左孩子
    pRoot->pLeft = (BinaryTree *)malloc(sizeof (BinaryTree));
    pRoot->pLeft->nValue = 2;
    pRoot->pFather = NULL;
    pRoot->pLeft->pFather = pRoot;

    //左孩子的左孩子
    pRoot->pLeft->pLeft = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pLeft->nValue = 4;
    pRoot->pLeft->pLeft->pFather = pRoot->pLeft;
    pRoot->pLeft->pLeft->pLeft = NULL;
    pRoot->pLeft->pLeft->pRight = NULL;
    
    //左孩子的右孩子
    pRoot->pLeft->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pLeft->pRight->nValue = 5;
    pRoot->pLeft->pRight->pFather = pRoot->pLeft;
    pRoot->pLeft->pRight->pLeft = NULL;
    pRoot->pLeft->pRight->pRight = NULL;
    //右孩子
    pRoot->pRight = (BinaryTree *)malloc(sizeof(BinaryTree));
    pRoot->pRight->nValue = 3;
    pRoot->pRight->pFather = pRoot;
    pRoot->pRight->pLeft = NULL;
    pRoot->pRight->pRight = NULL;

    return pRoot;
}
void Preorder(BinaryTree *pRoot){
    if(pRoot == NULL){
        return;
    }
    printf("%d ", pRoot->nValue);
    Preorder(pRoot->pLeft);
    Preorder(pRoot->pRight);
}

int main(){

    return 0;
}