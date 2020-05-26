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

//������Ա�
template <typename T>
void SeqList<T>::clear()
{
	this->len = 0;
	return;
}

//��ȡ���Ա������
template <typename T>
int SeqList<T>::getCapcity()
{

	return this->cap;
}

//��ȡ���Ա�ĳ���
template <typename T>
int SeqList<T>::getLen()
{

	return this->len;
}

//�����Ա��posλ�ò���Ԫ��item
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

//ɾ�����Ա�posλ�õ�Ԫ��
//����1��Ҫɾ����λ��
//����2������ɾ���Ľڵ�
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

//��ȡ���Ա�posλ�õ�Ԫ��
//����1��Ҫ��ȡ��λ��
//����2�������ȡ�Ľڵ�
template <typename T>
int SeqList<T>::get(int pos, T& t)
{
	t = this->nodeArr[pos];
	return 0;
}

