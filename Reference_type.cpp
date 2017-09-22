/*函数返回值是引用：引用就是一个变量的别名。
返回值是引用的，跟返回值是指针的差不多，都可以做为左值，因为它是可变的。
int t=5;
f(t)=100;
*/

#include<iostream>
using namespace std;
int leg = 4;//全局变量
int &dog(int num)
{
	
	leg = leg+num;
	return leg;
}

void main()
{
	int t = 5;

	dog(t) = 10;//先调用dog(t),这时全局变量leg=9，返回leg 再赋值
	//leg=10;所以。leg=10；
	//再次调用dog（t）,就有  leg=10+5 
	cout << dog(t)<<endl;//所以输出15,leg=15;

	t = dog(t);//调用dog(t),leg=15+5=20;所以t=20,leg=20;
	cout << dog(t) << endl;//leg= 20+20=40;
	system("pause");
}
