/* 目标：下标操作符的目的，通过对下标的使用如a[2]我们希望跟数组一样能调出已经在里面的值了，这时候也就只是需要将它的下标传进去，并且返回就行
但如果想通过下标能进行修改，这需要在设计的时候能赋予该功能，比如，在制作操作符重载的时候，对其&比如
char &operator[](int index);//;这个可以在main里面用a[2]='s'：。。。在调用a[1]时候，函数调用到了[]重载函数，*/

#include<iostream>
using namespace std;

class String
{
public:
	String(char *arr);
	//char operator[](int index);这个是不能在main里面用a[2]='s';
	
	char &operator[](int index);//;这个可以在main里面用a[2]='s'
	char operator[](int index)const;
private:
	char *arr;
	static  String errorMessage;//定义一个静态的字符串

};


String::String(char *arr)
{
	arr = arr ? arr : "";//判断字符串是否为空，是就赋值空字符
	this->arr = new char[strlen(arr)+1];
	strcpy_s((this->arr),strlen(arr)+1,arr);
	cout << arr<<endl;
}
String String::errorMessage("下标输入错误");
//成员函数，可以访问成员变量，并且因为成员变量是一个字符串，所以带入下标就能拿出对应字符串里面对应的值


//使用引用就可以修改里面的值
//String  b("okokoko");
//b[0] = 'A';可变的对象
char& String::operator[](int index)
{	
	//还要进行长度限制
	if (index > strlen(arr))
	{
		cout << "我收清白的";;
		throw errorMessage;
	}
	//char *arr;
	return arr[index];//char的返回值是字符串。
}


//String  b("okokoko");
//b[0] = 'A';不行
//这个不可变
char String::operator[](int index) const
{
	//;
	cout << strlen(this->arr)<<endl<<index<<endl;
	if (index > strlen(this->arr))
	{
		throw errorMessage;
	}
	return arr[index];
}




void main()
{

	String  a("hello  word");
	a[0] = 'a';
	String  const b("okokoko");
	//b[0]='A';
	cout<<b[0];
	system("pause");
}
