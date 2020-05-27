#include<stdio.h>


//ѡ�����򣬴�С������
void selectSort(int* arr, int len)
{
	int i, j, k;
	int tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = 0;

	for (i = 0; i < len; i++)
	{
		k = i;//���浱ǰԪ�ص��±�,���赱ǰԪ��Ϊ��СԪ��
		for (j = i + 1; j < len; j++)
		{//�ҳ������е���СԪ��,�����±걣����k��
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}

		//�������е���СԪ���뵱ǰԪ������λ��Ԫ�ؽ�����
		if (k != i)
		{
			tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

//�������򣬴�С������
void insertSort(int* arr, int len)
{
	int i, j, k;
	int tmp;
	i = j = k = tmp = 0;

	for (i = 1; i < len; i++)
	{
		tmp = arr[i];//���浱ǰҪ��Ԫ��
		k = i;
		for (j = i - 1; (j >= 0) && (arr[j] > tmp); j--)
		{
			arr[j + 1] = arr[j];//������Ҫ���Ԫ�غ���
			k = j;//k����Ҫ��Ԫ��Ҫ�����λ��
		}

		arr[k] = tmp;//���뵱ǰҪ��Ԫ��
	}

}

//ð������,��С����
void bubbleSort(int* arr, int len)
{
	int i, j;
	int tmp;
	i = j = 0;
	tmp = 0;

	for (i = len - 1 ; i >=0; i--)
	{

		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void printArr(int* arr, int len)
{

	for (int i = 0; i < len; i++)
	{

		printf("%d	", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[5] = { 5,3,1,2,4 };

	//selectSort(arr, 5);

	//insertSort(arr, 5);

	bubbleSort(arr, 5);

	printArr(arr, 5);

	return 0;
}