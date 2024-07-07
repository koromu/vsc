#include <iostream>

using namespace std;

// class 和 struct的主要区别都很像一个类

// 区别在：默认的访问权限

class C1{
    int m_a;// 什么都不修饰的，使用默认权限
};

struct S1{
    int m_a;// 什么都不写，这里的默认权限是公共权限
};


// struct 默认访问是公有成员，也就是 public
// class 默认访问是私有成员，也就是 private

int main()
{
    C1 c1;
    S1 s1;
    // c1.m_a = 100;// 报错了，是不可以访问的，不可以在类外访问的
    s1.m_a = 110;// 没报错，是可以访问然后修改的
    cout << s1.m_a << endl;

    // 此处还发现了一个问题, 文件名中不能有&符号
    return 0;
}