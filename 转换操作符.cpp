//ת��������
#include<iostream>
#include<string>
using namespace std;

class Dog
{
public:
	Dog(int age, double weight, string name) :age(age),
		weight(weight), name(name) {};

	//ת��������
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
	/*���򣺺���ǰû�з������ͣ�
	���������Ա
	return �������Ա
	int()������ͣ�����Ա��ɶ����дɶ��
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
	Dog a(2,4.4,"С��");

	int age;
	double  wei;
	string na;
	age = a;
	wei = a;
	na = a;
	cout << age << " " << wei << " " << na << endl;


	system("pause");
}