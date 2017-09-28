
int *p=0;//p是一个null指针
std::cout<<*p;//会导致不明确行为

char name[]="Darla";//name 是个数组，大小为6.别忘了微端的null；
char c =naem[10];//一个无效的数组索引，导致不明确行为
