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


BinaryTree *pRoot = NULL;   //全局变量根。
void RightRotate(BinaryTree *pTree){    //A的右旋
    //有可能需要换根，需要地址传递,所以传入的是指向指针的指针
    //也可以传入全局变量根。
    
    //右旋得有左
    if(pTree == NULL || pTree->pLeft == NULL){
        return;
    }
    //左孩子
    BinaryTree *pMark = pTree->pLeft;

    //修改三个孩子关系
    pTree->pLeft = pMark->pRight;
    pMark->pRight = pTree; 

    //判断旋转点是不是根（还有没有父亲）
    if(pTree->pFather != NULL){
        //旋转点不是根
        if(pTree->pFather->pLeft == pTree){
            //旋转点是左孩子
            pTree->pFather->pLeft = pMark;
        }else{
            //旋转点是右孩子
            pTree->pFather->pRight = pMark;
        }

    }
    else{
        //旋转点是根
        pRoot = pMark;
    }

    //修改父亲关系

    if(pTree->pLeft != NULL){
        //修改左孩子的父亲，若存在
        pTree->pLeft->pFather = pTree;
    }
    pMark->pFather = pTree->pFather;
    pTree->pFather = pMark;
}
void leftRotate(BinaryTree *pTree){    //A的右旋
    //有可能需要换根，需要地址传递,所以传入的是指向指针的指针
    //也可以传入全局变量根。
    //左旋得有右
    if(pTree == NULL || pTree->pRight == NULL){
        return;
    }
    //右孩子
    BinaryTree *pMark = pTree->pRight;
    //修改三个孩子关系
    pTree->pRight = pMark->pLeft;
    pMark->pLeft = pTree; 
    //判断旋转点是不是根（还有没有父亲）
    if(pTree->pFather != NULL){
        //旋转点不是根
        if(pTree->pFather->pLeft == pTree){
            //旋转点是左孩子
            pTree->pFather->pLeft = pMark;
        }else{
            //旋转点是右孩子
            pTree->pFather->pRight = pMark;
        }
    }
    else{
        //旋转点是根
        pRoot = pMark;
    }
    //修改父亲关系
    if(pTree->pRight != NULL){
        //修改右孩子的父亲，若存在
        pTree->pRight->pFather = pTree;
    }
    pMark->pFather = pTree->pFather;
    pTree->pFather = pMark;
}

int main(){
    pRoot = CreateBinaryTree();  //pRoot是全局变量
    Preorder(pRoot);  // 1 2 4 5 3 
    printf("\n");
    RightRotate(pRoot);
    Preorder(pRoot);   // 2 4 1 5 3
    printf("\n");
    leftRotate(pRoot);
    Preorder(pRoot);   // 1 2 4 5 3
    return 0;
}