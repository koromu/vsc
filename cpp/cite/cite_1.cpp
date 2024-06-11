#include <iostream>

// 作用给一个变量取别名

int main()
{
    int a = 10;// 一个四个字节大小的内存, 我们可以使用变量a来代表这个内存
    int &b = a;// 我们给b取了一个别名, b代表a这个内存, 两个变量代表同一个内存
    // 都可以操作这块内存
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    b = 20;
    // 也就是别名是b, 原名是a, 两个数据类型是需要相同的
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    
    
    return 0;
}