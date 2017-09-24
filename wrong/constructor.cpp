//错误的
class Test
{
private: 
  int a=0;
public:
    Test(Test obj){//这是错误的，在参数列表里不能创建对象。
    ....
    ....
    };
    //应该如此
    Test(Test &obj)
    {
    ....
    
    }

}
