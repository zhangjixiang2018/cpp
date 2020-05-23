#include<stdio.h>
#include<string.h>
#include<malloc.h>

//�������ڵ�
typedef struct BiNode
{
	int data;//����
	struct BiNode* lchild, * rchild;//���ӣ��Һ���
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


//�������
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

//��Ҷ�ӽڵ���
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

//�����ĸ߶�
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

//������
BiNode* copyTree(BiNode* tree)
{
	BiNode* newLeft = NULL;
	BiNode* newRight = NULL;
	BiNode* newRoot = NULL;

	if (tree == NULL)
	{
		return NULL;
	}

	newLeft = copyTree(tree->lchild);//����������
	newRight = copyTree(tree->rchild);//����������

	newRoot = (BiNode*)malloc(sizeof(BiNode));//�����µĸ��ڵ�
	if (newRoot == NULL)
	{
		printf("func copyTree() err -1\n");
		return NULL;
	}
	newRoot->data = tree->data;
	newRoot->lchild = newLeft;//�����������ӵ��µĸ��ڵ�
	newRoot->rchild = newRight;//�����������ӵ��µĸ��ڵ�

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


	//��������ϵ
	t1.lchild = &t2;

	t1.rchild = &t3;

	t2.lchild = &t4;

	t3.rchild = &t5;


	//�������
	perInDex(&t1);
	printf("\n");

	inInDex(&t1);
	printf("\n");

	//��Ҷ�ӽڵ���
	int sum;
	sum = 0;
	leafNum(&t1, &sum);
	printf("leaf sum : %d\n", sum);

	printf("���ĸ߶�Ϊ:%d\n", treeHight(&t1));


	printf("������\n");
	BiNode* newTree = copyTree(&t1);
	if (newTree == NULL)
	{
		printf("test01() copy tree fail\n");
		return;
	}
	printf("�������Ƶ���\n");
	inInDex(newTree);
}


int main()
{
	test01();
	return 0;
}