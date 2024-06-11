#include <iostream>

void my_print(const int& a)
{
    // a = 113;// 这时候就会组织我们操作这个值
    std::cout << a << std:: endl;
    return;
}

int main()
{
    // 其实引用是指针的
    int a = 110;
    
    // 自动转换成了int* const aa = &a
    // 而指针常量是指针指向补课更改, 也就是说初始化后, 不能发生改变
    int& aa = a;

    aa = 001;
    // 会变成一个*aa = 001, 所以实际上确实就是指针的操作
    std::cout << aa << std::endl;
    // 以上操作都是编译器帮我们操作的

    // 常量也是可以引用的的
    // 但是引用必须引用一块合法的区域, 不合法的区域就是常量区

    // int &tmp1 = 10; // 这是一个错误的代码. 因为常量区不是合法的区域
    const int& tmp2 = 10;
    // 这是实际上是编译器对代码进行了改变, 编译器生成了一个新的变量, 然后让我们指向了那个变量
    // int tmp3 = 10;
    // const int & ttmp3 = tmp3;

    a = 114;
    // 但是真正的实用场景实际上是在函数调用的时候, 我们防止在函数中进行修改这个值, 在函数中我们用常量接收
    my_print(a);

    return 0;
}