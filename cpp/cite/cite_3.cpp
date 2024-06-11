#include <iostream>

// 引用做函数的返回值

// 注意事项
// 不要返回局部变量的引用, 在栈区的局部变量

int& f1()
{
    int a = 11;
    static int b = 114;// 放在全局区, 是等程序结束之后系统释放
    // return a;// 局部变量退出函数是会被释放的, 所以返回时间不安全的, 不合法的, 被编译器禁止了

    return b;
}

int main()
{
    // int& a = f1();
    // 一些编译器是可以接收
    // 然后第一次是编译器做了保留, 然后第二次就是真正的会发现这个内存已经被释放了
    // std::cout << a << std::endl;
    // std::cout << a << std::endl;
    int& b = f1();// b是这个函数中的
    std::cout << b << std::endl;
    std::cout << b << std::endl;

    // 在前面中我们用b作为了这个返回的全局区的变量的别名
    f1() = 514;// 函数调用可以作为左值, 实际上就是对返回值进行操作
    // 如果函数的返回值是个引用, 那么这个值可以作为左值
    std::cout << b << std::endl;
    std::cout << b << std::endl;
    // 还是和一个变量存放的区域有关, 一个static的全局区的变量是不会在函数结束后被释放的

    return 0;
}