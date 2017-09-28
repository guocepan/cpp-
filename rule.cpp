#include <iostream>

using namespace std;
const  int Len = 66;
const int   Divs = 6;
void  subdivide(char  ar[],int  low,int  high,int level);
void main()
{
		
	char  ruler[Len];
	int i;
	for (i = 0; i < Len - 2; i++)
		ruler[i] = ' ';//无形的大括号。执行64次才到下面那一句
	
		ruler[Len - 1] = '\0';//字符串结束符号
		int Max = Len - 2;
		
	//	Max = Len - 2;
		int min = 0;
		//cout << min;
		ruler[min] = ruler[Max] = '|';
		cout << ruler << endl;

		for (i = 1; i <= Divs; i++)
		{
			subdivide(ruler,min,Max,i);
			cout << ruler << endl;
			for (int j = 1; j < Len - 2; j++)
				ruler[j] = ' ';
	
	    } 
		system("pause");
}

void  subdivide(char  ar[], int  low, int  high, int level)
{
	if (level == 0)
		return;
	int mid = (high+low)/2;
	ar[mid] = '|';
	subdivide(ar,low,mid,level-1);
	subdivide(ar, mid, high, level - 1);

}