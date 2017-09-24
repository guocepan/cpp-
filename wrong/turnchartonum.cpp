#include <iostream>
#include<string>
#include <sstream>
using namespace std;

class Test
{
private:
	int vale;
public:
	Test(int v) :vale(v) {};
	//    在参数里不能出现类对象
	Test(Test vv) :vale(vv.vale) {
	错误原因：当该函数调用时，复制构造函数Test(Test vv)传入的参数，是Test的一个
		实例，由于是传值参数，我们把形参复制到实参会调用构造函数。如果允许，就会在
		复制构造函数内调用复制构造函数，造成递归现象
	}
	//赋值构造函数这样写
	Test(Test &vv) :vale(vv.vale) {}
	int print(){
		cout << vale;
		return 0;
	}
};

void main()
{
	Test a = 10;
	Test b = a;
	b.print();
	system("pause");

}