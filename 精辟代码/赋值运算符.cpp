#include<iostream>
using namespace std;
class  T
{
private:
	char * m_pData;
public:
	T(char *pData = NULL);
	T&operator=(const T  &str);
	~T();
	void print();
};
T::T(char *pData)
{
	pData = pData ? pData : "";
	m_pData = new char[strlen(pData)+1];
	strcpy_s(m_pData,strlen(pData)+1,pData);

}

//
T& T::operator=(const T& str)
{
	//过滤掉 T b;b=b;的情况
	if (this != &str)
	{
		cout << "我来过了";
		cout << &str << endl;
		T strTemp(str);//建立临时对象，并初始化
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;

	}
	return *this;
}
T::~T()
{
	delete[]m_pData;
}

void T::print()
{
	cout << m_pData;
}
void main()
{
	T a("qewqwe");
	T b;
	T c=a;//这个不调=操作符重载
	b = a;//只有这样写 才会调用=操作符重载
	a.print();
	b.print();
	c.print();
	system("pause");

}