#include<iostream>
#include"seqList.cpp"
#include<string.h>

using namespace std;

struct Teacher
{
	int age;
	char name[64];
};

//²åÈëÔªËØ
void test01()
{
	SeqList<Teacher> myList(10);
	Teacher t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(Teacher));
	memset(&t2, 0, sizeof(Teacher));
	memset(&t3, 0, sizeof(Teacher));
	memset(&t4, 0, sizeof(Teacher));
	memset(&t5, 0, sizeof(Teacher));

	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;

	myList.insert(0, t1);
	myList.insert(0, t2);
	myList.insert(0, t3);
	myList.insert(0, t4);
	myList.insert(0, t5);

	cout << "list len	" << myList.getLen()<<endl;

	Teacher tmp;
	for (int i = 0; i < myList.getLen(); i++)
	{
		myList.get(i, tmp);
		cout << tmp.age<<"	";
	}


	
}

void test02()
{

}


int main()
{
	test01();
	return 0;
}