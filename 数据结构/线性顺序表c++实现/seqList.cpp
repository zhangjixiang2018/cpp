#include "seqList.h"
#include<iostream>

using namespace std;

template <typename T>
SeqList<T>::SeqList(int cap)
{
	nodeArr = new T[cap];
	this->cap = cap;
	this->len = 0;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] nodeArr;
	nodeArr = NULL;
	this->cap = 0;
	this->len = 0;
}

//清空线性表
template <typename T>
void SeqList<T>::clear()
{
	this->len = 0;
	return;
}

//获取线性表的容量
template <typename T>
int SeqList<T>::getCapcity()
{

	return this->cap;
}

//获取线性表的长度
template <typename T>
int SeqList<T>::getLen()
{

	return this->len;
}

//在线性表的pos位置插入元素item
template <typename T>
int SeqList<T>::insert(int pos, T& item)
{
	int ret = 0;

	if (pos<0 || pos>this->cap)
	{
		ret = -1;

		return ret;
	}

	if (pos > this->len)
	{
		pos = this->len;
	}

	for (int i = len ;  i > pos; i--)
	{
		this->nodeArr[i] = this->nodeArr[i - 1];
	}

	this->nodeArr[pos] = item;

	this->len++;

	return 0;
}

//删除线性表pos位置的元素
//参数1：要删除的位置
//参数2：保存删除的节点
template <typename T>
int SeqList<T>::del(int pos, T& t)
{
	t = this->nodeArr[pos];

	for (int i = pos+1; i < this.len; i++)
	{
		this->nodeArr[i-1] = this->nodeArr[i];
	}

	this->len--;
	return 0;
}

//获取线性表pos位置的元素
//参数1：要获取的位置
//参数2：保存获取的节点
template <typename T>
int SeqList<T>::get(int pos, T& t)
{
	t = this->nodeArr[pos];
	return 0;
}

