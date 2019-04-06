/*
二叉树: 非递归遍历
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE  1 

// 二叉树节点
typedef struct BINARYNODE {
	char ch;

	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

typedef struct BITREESTACKNODE{
	LinkNode node;
	BinaryNode* root;
	int flag;

}BiTreeStackNode;

//创建栈中的节点
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node , int flag){
	BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
	newnode->root = node;
	newnode->flag = flag;
	return newnode;
}

// 非递归遍历
void NonRecursion(BinaryNode* root){
	// 创建栈
	LinkStack* stack = Init_LinkStack();
	//把根结点扔到栈里
	Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(root,MY_FALSE));

	while(Size_LinkStack(stack) > 0){
		//先弹出栈顶元素
		BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);
		
		// 判断弹出的节点是否为空
		if(node->root == NULL){
			continue;
		}

		// 判断节点的状态
		if(node->flag == MY_TRUE){
			printf("%c",node->root->ch);
		}else{
			// 修改下面的压栈顺序就可以达到先序 中序 后序 遍历
			
            // 当前节点修改状态后入栈,
            node->flag = MY_TRUE;
            Push_LinkStack(stack,(LinkNode*)node);
            
			// 当前节点的右节点首先入栈
			Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->rchild,MY_FALSE));
			
			// 当前节点的左节点跟着入栈
			Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->lchild,MY_FALSE));
		}
	}
}

void Recursion(BinaryNode* root){
	if(root == NULL){
		return;
	}

	printf("%c",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}


void CresteBinaryTree() {
	//创建节点
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	
	// 建立节点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	NonRecursion(&node1);
}



int main(void) {
	CresteBinaryTree();

	return 0;
}
