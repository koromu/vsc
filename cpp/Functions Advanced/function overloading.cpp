#include <iostream>

using namespace std;

// 函数名字相同的时候, 只要参数的个数, 顺序, 类型不同
// 函数需要在用一个作用域下
// 就满足了函数重载 

void f1()
{
    cout << "空参f1" << endl;
    return;
}

void f1(int b, int a)
{
    cout << "有两个参数的f1" << endl;
    return;
}

void f1(double c, int a)
{
    cout << "有一个类型不同的f1" << endl;
    return;
}

void f1(int c, double a)
{
    cout << "顺序不同的f1" << endl;
    return;
}
// 但是一个注意的是, 不能根据返回值类型不同来进行函数重载

// 函数重载的注意事项

// 引用是可以作为函数重载的条件的
// 

void f1(int &a)
{
    cout << "通过引用重载的f1" << endl;
}

void f1(const int& a)
{
    cout << "通过常量引用重载的f1" << endl;
}

// void f1(int a)
// {
//     cout << "直接就是一个临时变量的f1" << endl;
// }// 这个函数和那个引用和常量引用的情况看起来很像, 所以不确定传进的是哪个函数

// void f1(int &a, int b = 10)
// {
//     cout << "有两个参数, 但是第二个有默认参数的话, 只传入一个值会进行调用函数" << endl;
// }

int main()
{
    f1();
    f1(1, 2);
    f1(2.0, 2);
    f1(2, 2.0);

    f1(10);// 这是一个常量, 所以走最接近的一个及时最后一个传入常量的f1
    int a = 110;
    f1(a);// 这是一个变量, 调用的是应用的那个f1
    return 0;
}