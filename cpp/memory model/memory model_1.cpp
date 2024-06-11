#include <iostream>
#include <string>

int * f1()
{
    int a = 10;
    int *p = & a;// 栈区的内存理论上在函数执行完之后会自动释放
    return p;// 这其中的形参和局部变量都是存放在栈中
} // 栈区的东西是有操作系统管理的
// 堆区的内存是程序管理开辟和使用的

int* f2()
{
    int *p =  new int(1010);// 但是指针本身是在栈中, 但是它指向的是堆区
    return p;// 而且这个new返回的是地址
}

std::string* f3()
{
    std::string *ps1 = new std::string("我是一个在堆中的字符串");
    return ps1;;
}

int * f4()
{
    int *p = new int(10);// 返回的是new的类型的指针
    return p;// 在堆区创造一个数据
}

void test04()
{
    int* p = f4();
    std::cout << *p << std::endl;
    std::cout << *p << std::endl;
    delete p;
    std::cout << *p << std::endl;// 此时出现的是乱码, 此时是非法操作, 一些编译器是无法运行的
    return ;
}

void test05()
{
    // 在堆区创建一个10个整形数据的数组
    int* arr =  new int[10];// 这个10代表的是由10个元素, 返回的是连续空间的首地址
    for(int i = 0 ; i < 10 ; i++)
    {
        // std::cout << arr[i] << std::endl;
        arr[i] = i + 100;
    }

    for(int i = 0 ; i < 10 ; i ++)
        std::cout << arr[i] << std::endl;
    
    // 释放数组
    delete[] arr;// 释放数组的时候, 需要知道是个数组加一个中括号, 然后再给地址
    // 也就是告诉系统, 我要释放的是一个长的数组, 否则会释放失败
 
    return;
}

int main()
{
    int *p1 = f1();
    std::cout << *p1 << std::endl;
    std::cout << *p1 << std::endl;// 第二次打印的是0, 实际上就是乱码, 在第一次还是给了机会的, 因为局部变量可能是误删除的


    // 以下是两个堆区new出来的东西, 由程序手动开辟, 手动释放
    int *p2 = f2();
    std::cout << *p2 << std::endl;


    std::string *ps1 = f3();
    std::cout << *ps1 << std::endl;
    std::cout << *ps1 << std::endl;// 此时输出两边都是正确的, 因为new出来的东西是程序管理的, 也就是程序员, 所以不会被误删除
    //除此之外还可以释放这个new对象


    // new的基本语法
    test04();
    // 关键字delete
    test05();

    return 0;
}