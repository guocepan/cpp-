//转换操作符
#include<iostream>
#include<string>
using namespace std;

class Dog
{
public:
	Dog(int age, double weight, string name) :age(age),
		weight(weight), name(name) {};

	//转换操作符
	operator int() const;
	operator double() const;
	operator string()const;

private:

	int age;
	double weight;
	string name;


};
Dog::operator int() const
{
	/*规则：函数前没有返回类型，
	必须是类成员
	return 必有类成员
	int()里的类型，看成员有啥，就写啥。
	*/
	return age;

}
Dog::operator double() const
{

	return weight;
}
Dog::operator string()const
{

	return name;

}





void  main()
{
	Dog a(2,4.4,"小明");

	int age;
	double  wei;
	string na;
	age = a;
	wei = a;
	na = a;
	cout << age << " " << wei << " " << na << endl;


	system("pause");
}