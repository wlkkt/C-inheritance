//#include <iostream>
//#include <string >
//using namespace std;
//
////基类Person
//class Person
//{
//public://共有
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//
//	string _name = "Mike";
//protected://保护
//	
//private://私有
//
//	int _age = 18;
//
//};
//
////派生类Student 
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _name << endl;
//		//cout << _age << endl;//派生类不能直接访问基类的私有成员
//		Print();//但是可以通过调用基类的成员函数间接访问
//	}
//protected:
//	int _stuid;//学号
//};
//
////派生类Teacher 
//class Teacher : public Person
//{
//protected:
//	int _jobid;//工号
//};


//int main()
//{
//	///////////////////////////////////////继承的概念和定义
//	//Student std;
//	////tea._name += 'x';
//	//std.Print();
//
//
//
//	//////////////////////////////////////基类和派生类对象的赋值转换
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
//		cout << "父类fun()" << endl;
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
//		cout << "子类fun()" << endl;
//	}
//};
//
//
//
//int main()
//{
//	//////////////////////////////////////继承中的作用域
//	B bb;
//	bb.fun(1);
//	//bb.fun();//尝试访问父类的fun函数失败
//	bb.A::fun();
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////派生类的默认成员函数
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
	string _name; // 姓名
};


class Student : public Person
{
public:
	// 父类+自己，父类的调用父类构造函数初始化（复用）
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

	// 子类的析构也会隐藏父类
	// 因为后续多态的需要，析构函数名字会被统一处理成destructor
	~Student()
	{
		// 显示写无法先子后父
		//Person::~Person();

		cout << _name << endl;
		cout << "~Student()" << endl;

		// 注意，为了析构顺序是先子后父，子类析构函数结束后会自动调用父类析构
	}

protected:
	int _num;	 //学号
	string _str;

	// 父类成员，当成一个整体的一个自定义类型成员
	// 子类的成员(跟以前一样)
	// a、内置类型
	// b、自定义类型
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
	Student s1(1, "xxxx", "张三");
	//Student s2(s1);
	////BB bb(1, "xxxx", "张三");

	//Student s3(2, "yyy", "李四");
	//s1 = s3;

	//Person p("李四");
	//p.~Person();

	return 0;
}