#include<iostream>
#include<string>
using namespace std;

class String
{
public:
	friend ostream& operator<<(ostream &out, String &item);

	String( char const *s ="");//构造函数，用string创建一个s对象
	String &operator=(String const&);//重载=。返回类型是String&
	String &operator=(char *str);
private:
	char *ptrChars;


};
//返回类型是String &类String函数名是operator;就是在类外实现函数
//当使用 对象a=b;时，默认的就将a变成主体，就是this指针的指向。
//b就是scr,这就是为啥赋值的时候可以只有一个参数的原因
String &String::operator=(String const &scr)
{
	//判断是不是相等的字符
	if (strlen(ptrChars) != strlen(scr.ptrChars))
	{
		//分配一个新的空间.strlen可以对字符串判断长度，
		//int arr[200]这个不是存字符串,char arr[200]="asdfsda";可以存在
		//跟char *arr ="asdfasdfsa";等价

		char *pnew = new char[strlen(scr.ptrChars)+1];//创建新的字符数组
		delete[] ptrChars;//释放掉之前的指针,删除掉里面的字符串
		ptrChars=pnew;//指向新的内存地址
		
	}
	strcpy_s(ptrChars,strlen(scr.ptrChars)+1,scr.ptrChars);
	return *this;//必须要返回当前对象；*号用来解掉引用
	//String &a =*this;因为this是指针；
	// int b;
	// int  &a=b;
}
//重载=用于传入的是指针字符串的时候；
String &String::operator=(char *str)
{
	if(strlen(ptrChars) != strlen(str))
	{
		char *pnew=new char[strlen(str)+1];	
		delete[]ptrChars;
		ptrChars =pnew;
	}
	strcpy_s(ptrChars,strlen(str)+1,str);
	return *this;
}


//构造函数，初始化对象时调用，并且开辟新空间，将传进来的参数保存起来
String::String (char  const *chars)
{
	cout << chars;

	//先判断参数传进来的是不是空字符
	//跟  x>y?x:y;一样的结构
	//chars ? chars : "";存不存在，为空就将空字符赋值给chars
	chars = chars ? chars : "";
	cout << chars;
	this->ptrChars = new char[strlen(chars)+1];
	strcpy_s(this->ptrChars, strlen(chars) + 1,chars);
}
//重载<<
ostream& operator<<(ostream &out, String &item)
{
	out << item.ptrChars <<endl;
	return out;//必须返回引用
}


void  main()
{
	String s("book");//调用构造函数
	String d("ww");
	s = d;//调用=重载，s默认为this指向的对象，d传进去的值
	cout << s;
	cout << d;
	char *arr="hello word";
	s=arr;
	cout << s;
	cout << d;

	system("pause");
}
