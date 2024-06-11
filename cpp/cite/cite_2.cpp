#include <iostream>

// 注意事项, 应用必须需要初始化, 而且初始化之后之后就不可以更改了

void my_swap_1(int &a, int &b)// 这里的a, b是一个别名, 然后就是可以更改的
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void my_swap_2(int *pa , int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    return;
}

int main()
{
    int a = 114;
    int c = 514;
    
    // int &b;
    
    // 这样的b会进行报错, 因为是必须需要初始化的
    
    int& b = a;

    b = c;// 这个时候把b的值赋值给了b的那块内存, 也是a的内存也被更改了
    // 这里的操作不是更改引用操作, 而是修改操作
    // 因为引用的操作, 在初始化之后是不会更改的

    int d = 1919;
    my_swap_1(d, a);// 本来d此时是1919, c是514
    // 因为是引用操作, 所以可以直接改变, 除此之外还可以进行地址传递操作
    // 如果只是值传递的话, 那么改变的是零时变量, 也就是形式参数, 所以函数外面的主函数中的数字并不会被改变

    std::cout << "d : " << d << " a :" << a << std::endl;// 514 , 1919
    my_swap_2(&d, &a);// 传入地址
    // 这样也是一种方式
    std::cout << "d : " << d << " a :" << a << std::endl;// 1919 , 514


    return 0;
}