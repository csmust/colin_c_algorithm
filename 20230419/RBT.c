/*(红黑树的增加)*/
#include<stdio.h>
#include<stdlib.h>

enum COLOR
{
    RED,
    BLACK
};

typedef struct node{
    int nValue;
    struct node *pLeft;
    struct node *pRight;
    struct node *pFather;
    int nColor;
} RBT;

RBT *pRoot = NULL;   //全局变量根。

void Preorder(RBT *pRoot){
    if(pRoot == NULL){
        return;
    }
    printf("value==%d\tcolor==%d\n", pRoot->nValue,pRoot->nColor);
    Preorder(pRoot->pLeft);
    Preorder(pRoot->pRight);
}

//右旋操作
void RightRotate(RBT *pTree){    //A的右旋
    //有可能需要换根，需要地址传递,所以传入的是指向指针的指针
    //也可以传入全局变量根。
    
    //右旋得有左
    if(pTree == NULL || pTree->pLeft == NULL){
        return;
    }
    //左孩子
    RBT *pMark = pTree->pLeft;

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

//左旋操作
void LeftRotate(RBT *pTree){    //A的左旋
    //有可能需要换根，需要地址传递,所以传入的是指向指针的指针
    //也可以传入全局变量根。
    //左旋得有右
    if(pTree == NULL || pTree->pRight == NULL){
        return;
    }
    //右孩子
    RBT *pMark = pTree->pRight;
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

//查找某个值放入后的父节点，并返回该父亲
RBT *Find(RBT *pTree,int nNum)
{
    if(pTree == NULL){
        return NULL;
    }

    while(pTree)
    {
        if(pTree->nValue > nNum)
        {
            if(pTree->pLeft == NULL)
                //左边有空可以放，找到了父亲
                return pTree;
            pTree = pTree->pLeft;
        }
        else if(pTree->nValue < nNum)
        {
            if(pTree->pRight == NULL)
                //右边有空可以放，找到了父亲
                return pTree;
            pTree = pTree->pRight;
        }
        else
        {
            //找到了，不需要放
            printf("data error.\n");
            exit(1);
        }
    }
}

//传入父亲，返回叔叔
RBT *GetUncle(RBT *pNode)
{
    if(pNode == pNode->pFather->pLeft)
        return pNode->pFather->pRight;
    else
        return pNode->pFather->pLeft;
}


//添加节点
void AddNode(RBT * pTree, int nNum)
{
    //有全局跟变量，不需要返回值

    RBT *pNodeFather = NULL;
    pNodeFather = Find(pTree, nNum); //找到父亲

    RBT *pNew = NULL;
    pNew = (RBT *)malloc(sizeof(RBT));
    pNew->nValue = nNum;
    pNew->pLeft = NULL;
    pNew->pRight = NULL;
    pNew->pFather = pNodeFather;
    pNew->nColor = RED; //新节点默认红色

    //空树
    if(pNodeFather == NULL){
        //根
        pRoot = pNew;
        pRoot->nColor = BLACK;
        return;
    }
    //非空树
    if(pNodeFather->nValue >nNum){
        //放左边
        pNodeFather->pLeft = pNew;
    }
    else{
        //放右边
        pNodeFather->pRight = pNew;
    }

    //父亲是黑色
    if(pNodeFather->nColor == BLACK){
        //不需要调整
        return;
    }

    //父亲是红色
    RBT *pUncle = NULL;
    RBT *pGrandpa = NULL;
    while (pNodeFather->nColor == RED)
    {
        pUncle = GetUncle(pNodeFather);
        pGrandpa = pNodeFather->pFather;

        //叔叔是红色
        if(pUncle != NULL && pUncle->nColor==RED )
        {
            //叔叔父亲爷爷变色
            pUncle->nColor = BLACK;
            pNodeFather->nColor = BLACK;
            pGrandpa->nColor = RED;
            //爷爷变红，可能会导致爷爷的父亲是红色，需要继续调整爷爷
            pNew = pGrandpa;
            pNodeFather = pNew->pFather;
            //爷爷是根
            if(pNodeFather == NULL){
                // 不能写pNodeFather->nColor = BLACK;  NULL没有nColor
                pRoot->nColor = BLACK;
                break;
            }
            //爷爷不是根，继续调整
            continue;
        }
        //叔叔是黑色的 含空的
        else if(pUncle == NULL || pUncle->nColor==BLACK)
        {
            //父亲是爷爷的左孩子
            if(pNodeFather == pGrandpa->pLeft)
            {
                //当前节点是父亲的右孩子
                if(pNew == pNodeFather ->pRight)
                {
                    pNew=pNodeFather;
                    LeftRotate(pNew);
                    //左旋后：父子关系颠倒
                    pNodeFather = pNew->pFather;
                }
                //当前节点是父亲的左孩子 此处不能写else if 因为上面的if可能会执行完接着执行下面
                if (pNew == pNodeFather->pLeft)
                {
                    pNodeFather->nColor = BLACK;
                    pGrandpa->nColor = RED;
                    RightRotate(pGrandpa);
                    break;
                }

                
            }

            //父亲是爷爷的右孩子
            else
            {
                //当前节点是父亲的左孩子
                if(pNew == pNodeFather->pLeft)
                {
                    pNew = pNodeFather;
                    RightRotate(pNew);
                    //右旋后：父子关系颠倒
                    pNodeFather = pNew->pFather;
                }
                //当前节点是父亲的右孩子
                if(pNew == pNodeFather->pRight)
                {
                    pNodeFather->nColor = BLACK;
                    pGrandpa->nColor = RED;
                    LeftRotate(pGrandpa);
                    break;
                }
            }
        }

    }
    
}

//创建红黑树
void CreateRBT(int arr[], int nLen)
{
    //有全局跟变量，不需要返回值
    if(arr == NULL || nLen <= 0){
        return;
    }

    int i;
    for (i = 0;i<nLen;i++){
        AddNode(pRoot, arr[i]);
    }
}


//查找节点
RBT *Search(RBT *pTree,int nNum)
{
    while(pTree)
    {
        if(pTree ->nValue == nNum)
        {
            return pTree;
        }
        else if(pTree->nValue > nNum)
        {
            pTree = pTree->pLeft;
        }
        else
        {
            pTree = pTree->pRight;
        }
    }
    //没找到
    return NULL;
}
//删除节点
void DelNode(RBT *pTree, int nNum)
{   
    if(pTree == NULL)
    {
        return;
    }
    //查找search
    RBT *pTemp = NULL;  //pTemp是要删除的节点
    pTemp = Search(pTree, nNum);
    if (pTemp == NULL)
    {
        return;
    }
    //2个孩子时需要转换成0个或1个孩子，通过值覆盖的方式
    if(pTemp->pLeft != NULL && pTemp->pRight != NULL)
    {
        RBT *pMark = pTemp;
        //找左子树的最大值
        pTemp = pTemp->pLeft;
        while(pTemp->pRight != NULL)
        {
            pTemp = pTemp->pRight;
        }
        //覆盖值
        pMark->nValue = pTemp->nValue;
    }

    RBT *pNode = pTemp->pFather; //pNode是要删除的节点的父亲
    //下面就只存在1或0个孩子
    //1. z是根 且 无子
    if(pNode == NULL && pTemp->pLeft == NULL && pTemp->pRight == NULL)
    {
        pRoot = NULL;

        free(pTemp);
        pTemp = NULL;
        return;
    }
    //2. z是根 且有一个孩子
    if(pNode == NULL && (pTemp->pLeft != NULL || pTemp->pRight != NULL))
    {
        pRoot = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight; //pTemp->pLeft不为空时，pRoot = pTemp->pLeft，否则pRoot = pTemp->pRight
        pRoot->nColor = BLACK;
        pRoot->pFather = NULL;
        
        free(pTemp);
        pTemp=NULL;
        return;
    }
    //3. z非根，红色
    if(pTemp->nColor == RED)
    {
        if(pTemp == pNode ->pLeft)
            pNode->pLeft = NULL;
        else
            pNode->pRight = NULL;
        free(pTemp);
        pTemp = NULL;
        return;
    }
    //4. z非根，黑色，有一个孩子
    if(pTemp->nColor == BLACK && (pTemp->pLeft != NULL || pTemp->pRight != NULL))
    {
        //z是父亲的左孩子   ，z的孩子则需要和z的父亲的左侧相连
        if(pTemp == pNode->pLeft)
        {
            
            pNode->pLeft = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight;
            pNode->pLeft->nColor = BLACK;
            pNode->pLeft->pFather = pNode;
        }
        //z是父亲的右孩子
        else
        {
            pNode->pRight = pTemp->pLeft ? pTemp->pLeft : pTemp->pRight;
            pNode->pRight->nColor = BLACK;
            pNode->pRight->pFather = pNode;
        }
        free(pTemp);
        pTemp = NULL;
        return;
    }
    //5. 黑色 非根 且无子
    RBT *pBrother = GetUncle(pTemp);//传入自己则返回兄弟。
    // 删除前先判断pTemp是父亲的左孩子还是右孩子
    if(pNode ->pLeft == pTemp)
    {
        pNode->pLeft = NULL;//置空
    }
    else
    {
        pNode->pRight = NULL;//置空
    }
    free(pTemp);
    pTemp = NULL;

    while(1)
    //删除后少了黑节点，需要调整
    {
        //兄弟是红色
        if(pBrother->nColor == RED)
        {
            pBrother->nColor = BLACK;
            pNode->nColor = RED;

            //兄弟在右侧.
            if(pBrother == pNode ->pRight)
            {
                LeftRotate(pNode);
                pBrother = pNode->pRight;  //左旋之后，兄弟换了，需要更新
                // continue;
            }
            //兄弟在左侧
            else
            {
                RightRotate(pNode);
                pBrother = pNode->pLeft;  //右旋之后，兄弟换了，需要更新
                // continue;
            }
        }
        //兄弟是黑色
        else{
            //两个侄子全黑
            if((pBrother->pLeft == NULL && pBrother->pRight ==NULL) || (pBrother->pLeft !=NULL && pBrother ->pLeft->nColor ==BLACK
                && pBrother->pRight !=NULL && pBrother->pRight->nColor == BLACK))
            {
                //父亲是红色
                if(pNode->nColor == RED)
                {
                    pBrother->nColor = RED;
                    pNode->nColor = BLACK;
                    break;  //END跳出调整
                }
                //父亲是黑色
                if(pNode->nColor == BLACK)
                {
                    pBrother->nColor = RED;
                    pTemp = pNode;  //父亲成为新的调整节点
                    pNode = pNode->pFather;                            
                    //如果父亲是NULL，则说明pTemp是根，直接跳出
                    if(pNode == NULL)
                    {
                        break;
                    }
                    pBrother = GetUncle(pTemp);
                }
            }
            //左侄子红 右侄子黑
            else if(pBrother->pLeft != NULL && pBrother ->pLeft ->nColor == RED &&
                (pBrother->pRight == NULL || pBrother->pRight->nColor == BLACK))
            {
                //兄弟是父亲的右侧
                if(pBrother == pNode->pRight)
                {
                    pBrother->nColor = RED;
                    pBrother->pLeft->nColor = BLACK;
                    RightRotate(pBrother);
                    pBrother = pNode->pRight;  //更新兄弟
                }
                //兄弟是父亲的左侧
                else
                {
                    pBrother->nColor = pNode->nColor;
                    pNode->nColor = BLACK;
                    pBrother->pLeft->nColor = BLACK;
                    RightRotate(pNode);
                    break;  //END跳出调整
                }
            }
            //右侄子是红色
            else
            {
                //兄弟是父亲的左侧
                if(pBrother == pNode ->pLeft)
                {
                    pBrother->nColor = RED;
                    pBrother->pRight->nColor = BLACK;
                    LeftRotate(pBrother);
                    pBrother = pNode->pLeft;  //更新兄弟
                }
                //兄弟是父亲的右侧
                else
                {
                    pBrother->nColor = pNode->nColor;
                    pNode->nColor = BLACK;
                    pBrother->pRight->nColor = BLACK;
                    LeftRotate(pNode);
                    break;  //END跳出调整
                }
            }
        }
    }

}

int main(){
    int arr[] = {11, 2, 14, 1, 7, 15, 5, 8};
    CreateRBT(arr,sizeof(arr)/sizeof(arr[0]));
    Preorder(pRoot);
    printf("\n");

    // AddNode(pRoot, 4);
    // Preorder(pRoot);
    // printf("\n");

    // AddNode(pRoot, 16);
    // Preorder(pRoot);
    // printf("\n");

    DelNode(pRoot, 1);
    Preorder(pRoot);
    printf("\n");

    DelNode(pRoot, 11);
    Preorder(pRoot);
    printf("\n");

    DelNode(pRoot, 14);
    Preorder(pRoot);
    printf("\n");

    return 0;
}