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
	//    �ڲ����ﲻ�ܳ��������
	Test(Test vv) :vale(vv.vale) {
	����ԭ�򣺵��ú�������ʱ�����ƹ��캯��Test(Test vv)����Ĳ�������Test��һ��
		ʵ���������Ǵ�ֵ���������ǰ��βθ��Ƶ�ʵ�λ���ù��캯������������ͻ���
		���ƹ��캯���ڵ��ø��ƹ��캯������ɵݹ�����
	}
	//��ֵ���캯������д
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