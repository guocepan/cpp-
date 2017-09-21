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
