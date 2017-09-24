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
	//���˵� T b;b=b;�����
	if (this != &str)
	{
		cout << "��������";
		cout << &str << endl;
		T strTemp(str);//������ʱ���󣬲���ʼ��
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
	T c=a;//�������=����������
	b = a;//ֻ������д �Ż����=����������
	a.print();
	b.print();
	c.print();
	system("pause");

}