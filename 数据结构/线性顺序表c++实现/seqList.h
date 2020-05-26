#pragma once

template <typename T>
class SeqList
{
private:
	int len;//���Ա���
	int cap;//���Ա�����
	T* nodeArr;//�ڵ�����

public:
	SeqList(int cap);

	~SeqList();

	//������Ա�
	void clear();

	//��ȡ���Ա������
	int getCapcity();

	//��ȡ���Ա�ĳ���
	int getLen();

	//�����Ա��posλ�ò���Ԫ��item
	int insert(int pos, T& item);

	//ɾ�����Ա�posλ�õ�Ԫ��
	//����1��Ҫɾ����λ��
	//����2������ɾ���Ľڵ�
	int del(int pos, T &t);

	//��ȡ���Ա�posλ�õ�Ԫ��
	//����1��Ҫ��ȡ��λ��
	//����2�������ȡ�Ľڵ�
	int get(int pos, T& t);

};

