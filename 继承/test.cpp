//#include <iostream>
//#include <string >
//using namespace std;
//
////����Person
//class Person
//{
//public://����
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//
//	string _name = "Mike";
//protected://����
//	
//private://˽��
//
//	int _age = 18;
//
//};
//
////������Student 
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _name << endl;
//		//cout << _age << endl;//�����಻��ֱ�ӷ��ʻ����˽�г�Ա
//		Print();//���ǿ���ͨ�����û���ĳ�Ա������ӷ���
//	}
//protected:
//	int _stuid;//ѧ��
//};
//
////������Teacher 
//class Teacher : public Person
//{
//protected:
//	int _jobid;//����
//};


//int main()
//{
//	///////////////////////////////////////�̳еĸ���Ͷ���
//	//Student std;
//	////tea._name += 'x';
//	//std.Print();
//
//
//
//	//////////////////////////////////////��������������ĸ�ֵת��
//	//Student st;
//	//Person p = st;
//	//Person& ref = st;
//	//Person* ptr = &st;
//
//	//ref._name += 'x';
//	//ptr->_name += 'y';
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <string >
//using namespace std;
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "����fun()" << endl;
//	}
//};
//
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "����fun()" << endl;
//	}
//};
//
//
//
//int main()
//{
//	//////////////////////////////////////�̳��е�������
//	B bb;
//	bb.fun(1);
//	//bb.fun();//���Է��ʸ����fun����ʧ��
//	bb.A::fun();
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////�������Ĭ�ϳ�Ա����
#include <iostream>
#include <string >
using namespace std;

class Person
{
public:
	Person(const char* name)
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};


class Student : public Person
{
public:
	// ����+�Լ�������ĵ��ø��๹�캯����ʼ�������ã�
	Student(int num, const char* str, const char* name)
		:Person(name)
		, _num(num)
		, _str(str)
	{
		cout << "Student()" << endl;
	}

	// s2(s1)
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
		, _str(s._str)
	{}

	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
			_str = s._str;
		}

		return *this;
	}

	// ���������Ҳ�����ظ���
	// ��Ϊ������̬����Ҫ�������������ֻᱻͳһ�����destructor
	~Student()
	{
		// ��ʾд�޷����Ӻ�
		//Person::~Person();

		cout << _name << endl;
		cout << "~Student()" << endl;

		// ע�⣬Ϊ������˳�������Ӻ󸸣���������������������Զ����ø�������
	}

protected:
	int _num;	 //ѧ��
	string _str;

	// �����Ա������һ�������һ���Զ������ͳ�Ա
	// ����ĳ�Ա(����ǰһ��)
	// a����������
	// b���Զ�������
};


//class BB
//{
//public:
//	BB(int num, const char* str, const char* name)
//		:_p(name)
//		,_num(num)
//		,_str(str)
//	{}
//private:
//	Person _p;
//	int _num;
//	string _str;
//};

int main()
{
	Student s1(1, "xxxx", "����");
	//Student s2(s1);
	////BB bb(1, "xxxx", "����");

	//Student s3(2, "yyy", "����");
	//s1 = s3;

	//Person p("����");
	//p.~Person();

	return 0;
}