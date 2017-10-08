
#include<iostream>
using namespace std;


//指针函数

//可以将最后一个字符'\0'复制过去；
char *mystrycpy(char *det,char *src)
{

	char *ret = det;//因为det++ 指针已经向后移动。只是保证指向在det的起始位置。
	if (det == NULL&&src == NULL)
		return ret;
	//后加语句，在执行完后才发挥作用。赋值。
	//在最后一个字符'\0'复制完成后跟'\0 '比较，所以‘\0'是已经复制过去了的。
	while ((*(det++) = *(src++)) != '\0')//==  (*det=*src)然后再向后移。先用后加就这么用起来了。
		;//空循环
	return ret;

}


//不能将最后一个字符'\0'复制过去
char *mystrcpy2(char *dest,char *scr)
{
	char *ret = dest;
	if (dest == NULL&&scr == NULL)//如果是空指针
		return ret;
	while (*scr != '/0')//字符串以'/0'结尾，不是空格  ' '是空格//在遇到‘/0’结束循环不能继续往下运行。
	{

		*dest = *scr;
		dest++;
		scr++;


	}

	return ret;
}

void main()
{

	char det[80] = {};
	char  src[] = "adfassd add";
	//mystrycpy(det, src);
	mystrcpy2(det,src);
	cout << det << endl;
	char *ret = NULL;

	char *ret = NULL;
	ret = mystrcpy2(det, src);
	cout << ret;
	system("pause");
	
	exit(0);
}
