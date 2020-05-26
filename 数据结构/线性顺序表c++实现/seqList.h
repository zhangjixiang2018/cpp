#pragma once

template <typename T>
class SeqList
{
private:
	int len;//线性表长度
	int cap;//线性表容量
	T* nodeArr;//节点数组

public:
	SeqList(int cap);

	~SeqList();

	//清空线性表
	void clear();

	//获取线性表的容量
	int getCapcity();

	//获取线性表的长度
	int getLen();

	//在线性表的pos位置插入元素item
	int insert(int pos, T& item);

	//删除线性表pos位置的元素
	//参数1：要删除的位置
	//参数2：保存删除的节点
	int del(int pos, T &t);

	//获取线性表pos位置的元素
	//参数1：要获取的位置
	//参数2：保存获取的节点
	int get(int pos, T& t);

};

