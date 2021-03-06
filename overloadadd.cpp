#include<iostream>
#include<string>
using namespace std;

class Sale_item
{
public:
	Sale_item(const string &book, const  unsigned units, const double amount)
		:isbn(book), units_sold(units), revenue(amount) {}
	//类成员，所以只有一个参数，其中另外一个隐形的是this，就是当前对象
	Sale_item& operator += (Sale_item &item);
	friend	ostream &operator<<(ostream &out, Sale_item &item);

	
private:
	string isbn;
	unsigned units_sold;
	double revenue;


};

Sale_item& Sale_item::operator +=(Sale_item &item)
{   
	
	//隐含的第一个对象是this
	this->units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;//返回本对象
}

Sale_item operator+(Sale_item &lhs,const Sale_item  &rhs)
{

	//好像String也可以这样初始化；
	string arr("asdfas");
	//Sale_item  ret(lhs);//1.用第一个参数去创建一个新的对象
	 Sale_item ret = lhs;//2. l和2两种方法都行
	//ret = ret+rhs;//用这个不行，不知是不是没有重载完的原因。
	
	ret += lhs;//+= 已经重载完毕
	return ret;//函数是一个类，所以返回的也是一个类

}
//重载<<，只能有这种方法。
ostream &operator<<(ostream &out,Sale_item &item)
{
	out << item.isbn << "  " << item.revenue << "  " << item.units_sold << endl;

	return out;
}
void main()
{
	Sale_item t(string("1212-122-12-X"),10,120.0);
	Sale_item t1(string("1212-122-12-X"), 10, 120.0);
	Sale_item result = t1 + t;
	cout << result;

	Sale_item t3(("1212-122-12-X"),100,120.0);
	result +=t3;//使用+= 操作符；	
	cout << result;
	system("pause");
}
