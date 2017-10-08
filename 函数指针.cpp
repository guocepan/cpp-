#include<iostream>

using namespace std;

int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;

}

int (*p[2])(int x,int y);//函数指针数组。
int(*q)(int x, int y);
int(*p_arr)[3];//指针数组。
void main()
{
	p[0] = add;
	p[1] = sub;
	int x = 10;
	int y = 20;

	cout<<p[0](x,y);
	cout<<p[1](x,y);

	system("pause");
	

}
