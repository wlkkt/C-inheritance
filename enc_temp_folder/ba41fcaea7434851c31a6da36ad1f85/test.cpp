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
//#include <iostream>
//#include <string >
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name)//��ʼ������
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)//��������,��this.s��
//		: _name(p._name)//this->_name��s._name��
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)//��ֵ����
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//
//	~Person()//��������
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//
//class Student : public Person
//{
//public:
//	//���� + ����
//	Student(int num, const char* str, const char* name)//��ʼ������
//		:Person(name)//����ľ͵��ø���ĳ�ʼ���б�
//		, _num(num)//����
//		, _str(str)//����
//	{
//		cout << "Student()" << endl;
//	}
//
//	// s2(s1)
//	Student(const Student& s)//��������,��const Student& this ,const Student& s��
//		:Person(s)//��������Ƭ����ʼ��һ����������ݣ����ø���Ŀ������죬Person��this,s��
//		, _num(s._num)//Ȼ���ٽ����������еĽ��г�ʼ��
//		, _str(s._str)
//	{}
//
//	Student& operator=(const Student& s)//��ֵ����
//	{
//		if (this != &s)//�����Լ����Լ���ֵ
//		{
//			Person::operator=(s);//���ø���ĸ�ֵ���أ������ָ������Ļ�����Ὣ����ĸ�ֵ�������أ�����ѭ�����������Լ��ĸ�ֵ�������ջ���
//			_num = s._num;
//			_str = s._str;
//		}
//
//		return *this;
//	}
//
//	// ���������Ҳ�����ظ���
//	// ��Ϊ������̬����Ҫ�������������ֻᱻͳһ�����destructor
//	~Student()//��������
//	{
//		cout << _name << endl;
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num;	 
//	string _str;
//
//};
//
//
//
//int main()
//{
//	
//	Student s1(1, "xxxx", "����");//��ʼ��
//	//Student s2(s1);//��������
//
//	//Student s3(2, "yyy", "����");//��ʼ��
//	//s1 = s3;//��ֵ����
//
//	//Person p("����");//��ʼ������
//	//p.~Person();//������������ֱ����ʾ����
//
//	return 0;
//}


/////////////////////////////////////////////////////////�̳�����Ԫ
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Student;//ǰ��������person����Ԫ������Ҫһ��Student�����͵Ķ���������������������Ԫ������Ϊû�п�ƥ��Ķ���ᱻ����
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//���Է���_name
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//���Է���//_stuNum
//protected:
//	int _stuNum;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	Display(p,s);
//	return 0;
//}

/////////////////////////////////////////////////////////�̳��뾲̬��Ա 
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	Person()//Ĭ�Ϲ���
//	{
//		++_count;//����Ĭ�Ϲ���++_count
//	}
//	Person(const Person& p)//��������
//	{
//		++_count;//���ÿ�������++_count
//	}
//	
//protected:
//	string _name;//����
//public:
//	static int _count; //ͳ���˵ĸ�������̬��Ա��
//};
//
//int Person::_count = 0;
//
//class Student :public Person
//{
//protected:
//	int _stuNum;//ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//
//int main()
//{
//	Person p;
//	Student s1;
//	Student s2;
//	Student s3;
//	Student s4(s3);
//	Graduate g1;
//
//
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//	cout << &Graduate::_count << endl;
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	cout << Graduate::_count << endl;
//	return 0;
//}

/////////////////////////////////////////////////////////���ӵ����μ̳к���������̳�
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	string _name; // ����
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

/////////////////////////////////////////////////////////�鿴�ڴ�
#include <iostream>
using namespace std;

class A
{
public:
	int _a;
};
 
//class B : public A
class B : virtual public A
{
public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}