
//string.h
#pragma once
#ifndef  STRING_H
#define STRING_H
class String
{
public:
	String(char const *chars = "");
	String(String const &str);
	~String();
	void display()const;
private:
	char *ptrChars;

};




#endif // ! STRING_H


//string.c
#include<iostream>
#include<cstring>
#include"string.h"
using namespace std;

String::String(char const *chars)
{
	chars = chars ? chars : "";//传过来的指针是不是空的，是就赋值给chars空；
	ptrChars = new char[strlen(chars) + 1];
	strcpy_s(ptrChars, strlen(chars) + 1, chars);
}
String::String(String const &str)
{
	ptrChars = new char[strlen(str.ptrChars) + 1];
	strcpy_s(ptrChars, strlen(str.ptrChars) + 1, str.ptrChars);

}
String::~String()
{
	delete[]ptrChars;

}

void String::display()const
{
	cout << ptrChars << endl;

}

//point.h
#ifndef POINT_H
#define POINT_H
#include"string.h"


#pragma once
//这个类拿来当做智能指针
class Pointer
{
public:
	Pointer();
	Pointer(String const &n);
	~Pointer();

	String &operator *();
	String *operator ->();
private:
	String *ptr;
	static String erroMessage;


};



//pointer.c
#include"point.h"
#include"string.h"

Pointer::Pointer() :ptr(0) {}

Pointer::Pointer(String const &n)
{
	ptr = new String(n);
}

Pointer::~Pointer()
{
	delete ptr;
}
String Pointer::erroMessage("Uninitalezd pointor");

String &Pointer::operator *()
{
	return *ptr;
}
String *Pointer::operator ->()
{
	return ptr;
}

//main.c
#include<iostream>
#include"string.h"
#include"point.h"

using namespace std;
int  main()
{
	String s("Hello String");

	s.display();
	String *ps = &s;//这个是一个普通的指针，容易产生野指针
	ps->display();

	Pointer p("asdfasdf");
	p->display();//使用了重载的 ->

	String pp = *p;//* ptr，使用了重载的*
	pp.display();
	system("pause");
	return 0;
}