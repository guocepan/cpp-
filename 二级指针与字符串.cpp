
#include<iostream>
#include<string>
using namespace std;
			//char **p =&str;
void copy(char **pp,int size)
{
	//分配给str空间。因为。p=&str; ->*p=*(&str)=str;
	*pp = (char *)malloc(size);
	strcpy_s(*pp,10,"hello");
}

void main()
{
	char *str = NULL;//只是防止野指针出现；想要给他东西，需要给他内存
	int size = 32;
	copy(&str,size);//传str的地址过去，所有的操作将都在str的内存上进行。
	//cout << str;


	char *arr = NULL;
	arr = (char*)malloc(32);
	strcpy_s(arr, 10, "hehehe");
	cout << arr;


	free(str);//那么释放掉就没问题。
	system("pause");
}
