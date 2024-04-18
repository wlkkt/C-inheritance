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
//#include <iostream>
//#include <string >
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name)//初始化队列
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)//拷贝构造,（this.s）
//		: _name(p._name)//this->_name（s._name）
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)//赋值重载
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//
//	~Person()//析构函数
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//
//class Student : public Person
//{
//public:
//	//父类 + 子类
//	Student(int num, const char* str, const char* name)//初始化队列
//		:Person(name)//父类的就调用父类的初始化列表
//		, _num(num)//子类
//		, _str(str)//子类
//	{
//		cout << "Student()" << endl;
//	}
//
//	// s2(s1)
//	Student(const Student& s)//拷贝构造,（const Student& this ,const Student& s）
//		:Person(s)//传引用切片，初始化一个父类的内容，调用父类的拷贝构造，Person（this,s）
//		, _num(s._num)//然后再将子类中特有的进行初始化
//		, _str(s._str)
//	{}
//
//	Student& operator=(const Student& s)//赋值重载
//	{
//		if (this != &s)//不能自己给自己赋值
//		{
//			Person::operator=(s);//调用父类的赋值重载，如果不指定父类的话子类会将父类的赋值重载隐藏，无限循环调用子类自己的赋值重载最后栈溢出
//			_num = s._num;
//			_str = s._str;
//		}
//
//		return *this;
//	}
//
//	// 子类的析构也会隐藏父类
//	// 因为后续多态的需要，析构函数名字会被统一处理成destructor
//	~Student()//析构函数
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
//	Student s1(1, "xxxx", "张三");//初始化
//	//Student s2(s1);//拷贝构造
//
//	//Student s3(2, "yyy", "李四");//初始化
//	//s1 = s3;//赋值重载
//
//	//Person p("李四");//初始化父类
//	//p.~Person();//析构函数可以直接显示调用
//
//	return 0;
//}


/////////////////////////////////////////////////////////继承与友元
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Student;//前向声明，person的友元函数需要一个Student类类型的对象，如果不事先声明则该友元函数因为没有可匹配的对象会被忽略
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//可以访问_name
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//可以访问//_stuNum
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

/////////////////////////////////////////////////////////继承与静态成员 
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	Person()//默认构造
//	{
//		++_count;//调用默认构造++_count
//	}
//	Person(const Person& p)//拷贝构造
//	{
//		++_count;//调用拷贝构造++_count
//	}
//	
//protected:
//	string _name;//姓名
//public:
//	static int _count; //统计人的个数（静态成员）
//};
//
//int Person::_count = 0;
//
//class Student :public Person
//{
//protected:
//	int _stuNum;//学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究项目
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

/////////////////////////////////////////////////////////复杂的菱形继承和菱形虚拟继承
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

/////////////////////////////////////////////////////////查看内存
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