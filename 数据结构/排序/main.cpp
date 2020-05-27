#include<stdio.h>


//选择排序，从小到大排
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
		k = i;//缓存当前元素的下标,假设当前元素为最小元素
		for (j = i + 1; j < len; j++)
		{//找出数组中的最小元素,将其下标保存在k中
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}

		//将数组中的最小元素与当前元素所在位置元素交换，
		if (k != i)
		{
			tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

//插入排序，从小到大排
void insertSort(int* arr, int len)
{
	int i, j, k;
	int tmp;
	i = j = k = tmp = 0;

	for (i = 1; i < len; i++)
	{
		tmp = arr[i];//缓存当前要排元素
		k = i;
		for (j = i - 1; (j >= 0) && (arr[j] > tmp); j--)
		{
			arr[j + 1] = arr[j];//将符合要求的元素后移
			k = j;//k保存要排元素要插入的位置
		}

		arr[k] = tmp;//插入当前要排元素
	}

}

//冒泡排序,从小到大
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