#include<stdio.h>
#include<string.h>
#include<malloc.h>

//二叉树节点
typedef struct BiNode
{
	int data;//数据
	struct BiNode* lchild, * rchild;//左孩子，右孩子
}BiNode;

void perInDex(BiNode* tree)
{
	if (tree == NULL)
	{
		return;
	}

	printf("%d	", tree->data);
	perInDex(tree->lchild);
	perInDex(tree->rchild);
}


//中序遍历
void inInDex(BiNode* tree)
{
	if (tree == NULL)
	{
		return;
	}

	
	inInDex(tree->lchild);
	printf("%d	", tree->data);
	inInDex(tree->rchild);
}

//求叶子节点数
void leafNum(BiNode* tree, int* sum)
{
	if (tree == NULL)
	{
		return;
	}

	if (tree->lchild == NULL && tree->rchild == NULL)
	{
		(*sum)++;
	}

	leafNum(tree->lchild,sum);
	leafNum(tree->rchild,sum);
}

//求树的高度
int treeHight(BiNode* tree)
{
	int tmp=0;
	int lHight = 0;
	int rHight = 0;

	if (tree == NULL)
	{
		return 0;
	}

	lHight = treeHight(tree->lchild);
	rHight = treeHight(tree->rchild);

	tmp = (lHight > rHight) ? lHight : rHight;
	tmp++;

	return tmp;
}

//复制树
BiNode* copyTree(BiNode* tree)
{
	BiNode* newLeft = NULL;
	BiNode* newRight = NULL;
	BiNode* newRoot = NULL;

	if (tree == NULL)
	{
		return NULL;
	}

	newLeft = copyTree(tree->lchild);//构造左子树
	newRight = copyTree(tree->rchild);//构造右子树

	newRoot = (BiNode*)malloc(sizeof(BiNode));//创建新的根节点
	if (newRoot == NULL)
	{
		printf("func copyTree() err -1\n");
		return NULL;
	}
	newRoot->data = tree->data;
	newRoot->lchild = newLeft;//将左子树连接到新的根节点
	newRoot->rchild = newRight;//将右子树连接到新的根节点

	return newRoot;

}



void test01()
{
	BiNode t1, t2, t3, t4, t5;

	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;


	//建立树关系
	t1.lchild = &t2;

	t1.rchild = &t3;

	t2.lchild = &t4;

	t3.rchild = &t5;


	//先序遍历
	perInDex(&t1);
	printf("\n");

	inInDex(&t1);
	printf("\n");

	//求叶子节点数
	int sum;
	sum = 0;
	leafNum(&t1, &sum);
	printf("leaf sum : %d\n", sum);

	printf("树的高度为:%d\n", treeHight(&t1));


	printf("复制树\n");
	BiNode* newTree = copyTree(&t1);
	if (newTree == NULL)
	{
		printf("test01() copy tree fail\n");
		return;
	}
	printf("遍历复制的树\n");
	inInDex(newTree);
}


int main()
{
	test01();
	return 0;
}