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

	// ��������
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
	// �������Զ����ɵ�Ĭ�Ϲ����Զ����ø����Ĭ�Ϲ���
public:
	// ��ʽ����Ĺ��캯��Ҳ�Զ����ø����Ĭ�Ϲ���
	// �ȵ��ø��๹�죬�ٵ��ñ�����
	// �ڳ�ʼ���б��е��ø��๹��
	// �����Ա�����������ʼ���б��г�ʼ��

	// �����Ա�����ø��๹�캯�����г�ʼ��
	Student(int id = 100, int age = 10){
		cout << "Student(int ,int)" << endl;
	}

	// �������Զ����ɵĿ��������Զ����ø���Ŀ�������
//����ʽ����ͻ���ø���Ŀ�������
	// ��ʽ����֮����ø���Ĺ��캯��

// ��ʽ����Ŀ������죬�Զ����ø����Ĭ�Ϲ��죬���Ǹ���Ŀ�������
	
	// ��ʽ������ø��࿽�����죬���ø��࿽������ʱ������Ƭ������
	Student(const Student& st)
		//:Person(st)
		:Person(st._num) // ��ʱ����Ĭ�Ϲ���
		, _num(st._num)
	{
		cout << "Student(const Student& st)" << endl;
	}

	// �������Զ����ɵĸ�ֵ����������Զ����ø���ĸ�ֵ���������

// û����ʽ����˸�ֵ������͵��ø��ำֵ�����
	// ͬ�����غ���,��˲�����ø���ĸ�ֵ�������
	// ���ำֵ������͸��ำֵ���������ͬ������
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
	cout << "��ֵ�����" << endl;
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
	char _sex = '��';
// protected:���ⲻ�ɼ������ڲ�������Ŀɼ�
	// ����Ȩ�����⣺��˴󲿷����������public�̳�Ȩ��
//protected:
public:
	int _id=100;
	string _name="peter";
	int _age=18;
	// ˽�г�Ա�������в��ɼ�
private:
	string _description;
};

void showId(){
	cout << "glabol showId()" << endl;
}
class Student :public Person{
public:
	//���࣬������������Ƕ����ģ���ͬ���������п�����ͬ���ĳ�Ա
	// ������Ҫ��ͬһ�������򣬲�ͬ��������������

	// �ֲ�������������ò�Ҫ��ͳ�Ա����һ��������
	void setNum(int _num){
		this->_num = _num;
	}
	void showId(){
		// ͬ�����أ������е�ͬ����Ա�������е�ͬ����Ա����˲��ṹ�ɳ�ͻ��ֻ���γ���һ��ͬ������
		cout << _id << endl;
		// ȡ�������ͬ����Ա
		cout << Person::_id << endl;

		// ���ø���showId
		Person::showId();
		//showId();
		// ����ȫ�ֺ���
		::showId();
	}

	int dd(){

		// ͬ�����أ���������
		Person::dd(10);
	}
public:
	int _id = 1;
	int _num = 2020;
};

 // ȫ�ֱ���_id
// �������ط����ʱ�����������޶����������ֻ����������Ա����
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
		// ��ʱ����ı䣬��Ϊ��Ա��������ı����Ǿֲ����������ǳ�Ա����
		// �ֲ�������δ�޸ĳ�Ա������ͬ������
		// �ͽ�ԭ�������Ҫ����Ա������ֵ��Ҫ+this->
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
//	char _sex = '��';
//// protected:���ⲻ�ɼ������ڲ�������Ŀɼ�
//	// ����Ȩ�����⣺��˴󲿷����������public�̳�Ȩ��
////protected:
//public:
//	string _name="peter";
//	int _age=18;
//	// ˽�г�Ա�������в��ɼ�
//private:
//	string _description;
//};
//
///*
//// �̳У�����븴��
//// Student����Person�����Ա
//// �̳У�
//// class/struct ���� : ��Ҫ�̳е���	
//// ����/������ ����/����
//class Student :public Person{
//public:
//	void show(){
//		// �˴�˽�г�Ա���ɼ�����������ȷʵ�и��෢˽�г�Ա
//		//cout << _description << endl;
//		cout << _age;
//	}
//};
//
//class protectedStudent :protected Person{
//	// �˴������˽�г�Ա�����ɼ�
//};
//*/
//
//// �̳У��༶����븴��
//// 1���̳з�ʽ��public,protected,private
//// 2��protected����Ȩ��/private����Ȩ�� : 
///*
//		protected: �ڵ�ǰ�������ɼ����������ط����ɼ�
//		private:�ڵ�ǰ��ɼ����������ط����ɼ�
//
//		3�������Ա�������еķ���Ȩ�ޣ�min(��Ա�ڸ����е�ԭʼ����Ȩ��,�̳з�ʽ)
//		4��һ�㶼�ǹ��м̳У�protected/private �̳к���ʹ��/��������
//			˽�м̳кͱ����̳�һ�㶼����
//		5��class�������Ĭ�ϼ̳з�ʽ������ڼ̳е�ʱ�򲻼�private,protected�ȹؼ��֣�Ĭ�ϼ̳з�ʽ��һ��˽�е�
//			�����struct������ࣺĬ�ϼ̳з�ʽ�ǹ��е�
//
//*/
////struct ������ࣺĬ�ϼ̳з�ʽΪ���е�
//// class ������ࣺĬ�Ϸ�ʽΪ˽�м̳�
//
////void test(){
////	Person p;
////	p.print();
////	// ����̳з�ʽΪprotected/private���Ӹ���̳����������г�Ա���Ȩ��Ϊprotected/private
////}
//
//class Student :public Person{
//protected:
//	int _num;
//};
//
//// ��Ƭ�ǰ�ȫ������Ϊ��Ƭ֮��ĳ�Ա���ڣ���֮��ء����
//// ��Ա���ڷ��ʼ��ɣ����پ��޷����ʣ����ʾͻ�Խ��
//// ���ำֵ������
//
//void test(){
//	Person p;
//	Student st;
//
//	// ��Ƭ�������������ָ�룬���ÿ���ֱ�Ӹ�ֵ���������ָ�룬���ã��˴�������ʽ����ת�����˴�����Ƭ
//	// ѧ������
//	// ����ѧ��-->��һ������
//	// ��֮������
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	// ����ָ�룬���ò���ֱ�Ӹ�ֵ������ָ�룬���á�
//	// ����ͨ��ǿ������ת�������и�ֵ
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
////	// protected:���ⲻ�ɼ������ڲ�������ɼ�
////protected:
////	string _name = "peter";
////	
////	int _age = 18;
////private:
////	char _sex;
////};
////
////// �̳У�����븴��
////
////// class/struct ���� : ��Ҫ�̳е���
//////		 ����/������	����/����
////class Student :public Person{
////public:
////	void show(){
////		cout << _name << "\t" << _id << "\t" << _age << endl;
////
////		// ����˽�г�Ա�����ɷ��ʸ���private��Ա�������в��ɼ�����������ȷʵ�и����˽�г�Ա�������� ���׵�˽��Ǯ���е����㲻֪����
////		//cout << _sex << endl;
////	}
////};
////
////// ����̳з�ʽΪprotected/private���������г�Ա���Ȩ�޾���protected
////// �����ⲻ�ɼ�
////// �����Ա�ı�����Ȩ��Ϊ��Ա���ڸ����Լ��̳�Ȩ�޶���ȡ��С
////class Teacher :protected Person{
////
////};
////class Empty{
////
////};
////
////// class�������Ĭ�ϼ̳з�ʽ
////// Ĭ�ϼ̳з�ʽΪ˽�е�
////class privateStudent :Person{
////
////};
////// struct�������Ĭ�ϼ̳з�ʽΪ���е�
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
////	/// ��Ƭ�������������ָ�룬���ÿ���ֱ�Ӹ�ֵ���������ָ�룬����
////	// ������ʽ����ת�����˴�ʹ��Ƭ
////	// ���·�ʽ֧�֣���֮��֧��
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