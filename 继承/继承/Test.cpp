#define _CRT_SECURE_NO_WARNGINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Person{

public:
	Person(int id = 10, int age = 20)
		:_id(id)
		, _age(age)
	{
		cout << "Person(int ,int)" << endl;
	}
	Person(int id, int age, int num){
		cout << "Person(int id, int age, int num)" << endl;
	}

	// 拷贝构造
	Person(const Person& p)
		:_id(p._id)
		, _age(p._age)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p){
		if (this != &p){
			_id = p._id;
			_age = p._age;
		}
		cout << "Person& operator=(const Person& p)" << endl;
		return *this;
	}
public:
	int _id;
	int _age;
};

class Student :public Person{
	// 编译器自动生成的默认构造自动调用父类的默认构造
public:
	// 显式定义的构造函数也自动调用父类的默认构造
	// 先调用父类构造，再调用本身构造
	// 在初始化列表中调用父类构造
	// 父类成员不能在子类初始化列表中初始化

	// 父类成员必须用父类构造函数进行初始化
	Student(int id = 100, int age = 10){
		cout << "Student(int ,int)" << endl;
	}

	// 编译器自动生成的拷贝构造自动调用父类的拷贝构造
//不显式定义就会调用父类的拷贝构造
	// 显式定义之后调用父类的构造函数

// 显式定义的拷贝构造，自动调用父类的默认构造，不是父类的拷贝构造
	
	// 显式定义调用父类拷贝构造，调用父类拷贝构造时，有切片操作、
	Student(const Student& st)
		//:Person(st)
		:Person(st._num) // 此时就是默认构造
		, _num(st._num)
	{
		cout << "Student(const Student& st)" << endl;
	}

	// 编译器自动生成的赋值运算符函数自动调用父类的赋值运算符函数

// 没有显式定义此赋值运算符就调用父类赋值运算符
	// 同名隐藏函数,因此不会调用父类的赋值运算符‘
	// 子类赋值运算符和父类赋值运算符构成同名隐藏
	Student& operator=(const Student& st){
		if (this != &st){
			Person::operator=(st);
				//_id = st._id;
			//_age = st._age;
			_num = st._num;
		}
		cout << "Student& operator=(const Student& st)" << endl;
		return *this;
	}
private:
	int _num=10;
};
void test(){
	Student st;
	//Person p;
	//Person cp(p);
	Student cps(st);
}

void test2(){
	Student st;
	Student st2(1, 1);
	cout << "赋值运算符" << endl;
	st2 = st;
}
int main(){
	test2();
	//test();
	system("pause");
	return 0;
}
/*
class Person{
public:
	void print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	void showId(){
		cout << "showId()" << endl;
	}

	void dd(int a){

	}
public:
	char _sex = '男';
// protected:类外不可见，类内部和子类的可见
	// 鉴于权限问题：因此大部分情况都定义public继承权限
//protected:
public:
	int _id=100;
	string _name="peter";
	int _age=18;
	// 私有成员在子类中不可见
private:
	string _description;
};

void showId(){
	cout << "glabol showId()" << endl;
}
class Student :public Person{
public:
	//父类，子类的作用域都是独立的，不同的作用域中可以有同名的成员
	// 重载需要在同一个作用域，不同的作用域不能重载

	// 局部变量变量名最好不要起和成员变量一样的名字
	void setNum(int _num){
		this->_num = _num;
	}
	void showId(){
		// 同名隐藏：父类中的同名成员被子类中的同名成员，因此不会构成冲突，只是形成了一个同名隐藏
		cout << _id << endl;
		// 取出父类的同名成员
		cout << Person::_id << endl;

		// 调用父类showId
		Person::showId();
		//showId();
		// 调用全局函数
		::showId();
	}

	int dd(){

		// 同名隐藏：不是重载
		Person::dd(10);
	}
public:
	int _id = 1;
	int _num = 2020;
};

 // 全局变量_id
// 在其他地方访问必须加上域名限定符，否则就只会访问自身成员变量
int _id = 200;
class Teacher{
public:
	int _id;
};


void test(){
	Student st;
	
	st.showId();
	//cout << st._num << endl;
	//st.setNum(1999);
	/*	
		// 此时不会改变，因为成员函数里面的变量是局部变量，并非成员变量
		// 局部变量并未修改成员变量，同名隐藏
		// 就近原则，如果需要给成员变量赋值就要+this->
		void setNum(int _num){
		_num = _num;
//	}
//	*/
//	//cout << st._num << endl;
//}
//
//*/


//
//class Person{
//public:
//	void print(){
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	char _sex = '男';
//// protected:类外不可见，类内部和子类的可见
//	// 鉴于权限问题：因此大部分情况都定义public继承权限
////protected:
//public:
//	string _name="peter";
//	int _age=18;
//	// 私有成员在子类中不可见
//private:
//	string _description;
//};
//
///*
//// 继承：类代码复用
//// Student包含Person对象成员
//// 继承：
//// class/struct 类名 : 需要继承的类	
//// 子类/派生类 父类/基类
//class Student :public Person{
//public:
//	void show(){
//		// 此处私有成员不可见，但是子类确实有父类发私有成员
//		//cout << _description << endl;
//		cout << _age;
//	}
//};
//
//class protectedStudent :protected Person{
//	// 此处父类的私有成员并不可见
//};
//*/
//
//// 继承：类级别代码复用
//// 1、继承方式：public,protected,private
//// 2、protected访问权限/private访问权限 : 
///*
//		protected: 在当前类和子类可见，在其他地方不可见
//		private:在当前类可见，在其他地方不可见
//
//		3、父类成员在子类中的访问权限：min(成员在父类中的原始访问权限,继承方式)
//		4、一般都是公有继承：protected/private 继承很少使用/几乎不用
//			私有继承和保护继承一般都不用
//		5、class定义的类默认继承方式：如果在继承的时候不加private,protected等关键字，默认继承方式是一个私有的
//			如果是struct定义的类：默认继承方式是公有的
//
//*/
////struct 定义的类：默认继承方式为公有的
//// class 定义的类：默认方式为私有继承
//
////void test(){
////	Person p;
////	p.print();
////	// 子类继承方式为protected/private，从父类继承下来的所有成员最低权限为protected/private
////}
//
//class Student :public Person{
//protected:
//	int _num;
//};
//
//// 切片是安全的是因为切片之后的成员还在，反之则亍存在
//// 成员还在访问即可，不再就无法访问，访问就回越界
//// 子类赋值给父类
//
//void test(){
//	Person p;
//	Student st;
//
//	// 切片操作：子类对象，指针，引用可以直接赋值给父类对象，指针，引用，此处不是隐式类型转换，此处叫切片
//	// 学生是人
//	// 人是学生-->不一定成立
//	// 反之不成立
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	// 父类指针，引用不能直接赋值给子类指针，引用。
//	// 可以通过强制类型转换，进行赋值
//	Student* sp = (Student*)&p;
//
//	Student& rp = (Student&)p;
//}
//int main(){
//
//
//	system("pause");
//	return 0;
//}
////
////
////class Person{
////public:
////	void print(){
////		cout << "name:" << _name << endl;
////		cout << "age:" << _age << endl;
////	}
////
////public:
////	int _id;
////	// protected:类外不可见，类内部和子类可见
////protected:
////	string _name = "peter";
////	
////	int _age = 18;
////private:
////	char _sex;
////};
////
////// 继承：类代码复用
////
////// class/struct 类名 : 需要继承的类
//////		 子类/派生类	父类/基类
////class Student :public Person{
////public:
////	void show(){
////		cout << _name << "\t" << _id << "\t" << _age << endl;
////
////		// 父类私有成员，不可访问父类private成员在子类中不可见，但是子类确实有父类的私有成员（类似于 父亲的私房钱，有但是你不知道）
////		//cout << _sex << endl;
////	}
////};
////
////// 子类继承方式为protected/private，子类所有成员最低权限就是protected
////// 在类外不可见
////// 父类成员的被访问权限为成员所在父类以及继承权限二者取最小
////class Teacher :protected Person{
////
////};
////class Empty{
////
////};
////
////// class定义的类默认继承方式
////// 默认继承方式为私有的
////class privateStudent :Person{
////
////};
////// struct定义的类默认继承方式为公有的
////struct publicStudent :Person{
////
////};
////void test(){
////	cout << sizeof(Person) << endl;
////	cout << sizeof(Student) << endl;
////	cout << sizeof(Empty) << endl;
////
////	Student  st;
////	st.print();
////}
////
////// 
////int test2(){
////	Person p;
////	Student st;
////
////	/// 切片操作：子类对象，指针，引用可以直接赋值给父类对象，指针，引用
////	// 不是隐式类型转换，此处使切片
////	// 以下方式支持，反之则不支持
////	p = st;
////	Person& rs = st;
////	Person* ptrs = &st;
////
////}
////int main(){
////	test();
////	system("pause");
////	return 0;
////}