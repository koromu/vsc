#include <iostream>

using namespace std;

// 一个参数只是写类型

void f1(int a, int)
{
    cout << "f1" << endl;
    return;
}

void f2(int b, int = 99)
{
    cout << "f2" << endl;
    return;
}

int main()
{
    // 函数中是可以有占用参数的
    f1(10, 99);// 虽然这个第二个值目前用不到, 而且这个默认参数也可以由默认参数
    f2(10);// 有了默认参数后都可以不用传入一个占位的值了
    return 0;
}