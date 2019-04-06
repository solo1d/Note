/*
二叉树: 基础递归遍历方式
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 二叉树节点
typedef struct BINARYNODE {
	char ch;

	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

// 递归遍历
void Recursion(BinaryNode* root) {

	if (root == NULL) {
		return;
	}

	// 先访问根节点

//	printf("%c ", root->ch);   // 先序遍历
 
	// 再遍历左子树
	Recursion(root->lchild);
//	printf("%c ", root->ch);   // 中序遍历

	// 再遍历右子树
	Recursion(root->rchild);
//	printf("%c ", root->ch);   // 后序遍历
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


	// 递归遍历
	Recursion(&node1);
	printf("\n");
}


int main(void) {
	CresteBinaryTree();


	return 0;
}