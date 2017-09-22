#include <iostream>
using namespace std;

void main()
{
  char arr[100]{};//初始化为空 ，因为不知道动态的怎么搞，就先假设有100个字符
  cin>>arr;
  int size_arr = strlen(arr);//计算字符个数
  for(int i = size_arr;i >=0;i--)
  {
      cout<<arr[i];
  }
  cout<<endl;
  system("pause");
}
