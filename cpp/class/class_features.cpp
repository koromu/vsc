#include <iostream>

using namespace std;

// 对象的初始化和清理

// 分别对应的是构造函数和析构函数
// 可以自己写出来, 如果自己不写的话, 那么编译器会自己帮我们做出空的实现

// 1. 构造函数的语法 

// 返回值不需要写
// 函数名和类名相同
// 构造函数可以有参数, 可以发生重载
// 一个对象只会调用一次构造函数

// 2. 析构函数的语法

// 析构函数不能有参数, 也就不可以重载
// 其他的区别就是在函数前面有一个~

class person{
    
private:

    string name;
    int age;

public:
    person()
    {
        cout << "构造函数的调用, 并且为了在主函数, 或者其他类外的情况能够调用到这个, 所以需要到public作用域里面" << endl;
    }

    person(const person &a)// 这个参数就是拷贝构造函数的构造方法, 一般用于构造一个完全一样的另一个对象
    {
        cout << "这是一个拷贝构造函数" << endl;
        name = a.name;
        age = a.age;
    }

    person(int a, string n)
    {
        cout << "这是一个有参构造函数" << endl;
        name = n;
        age = a;
    }

    ~person()
    {
        cout << "析构函数的调用" << endl;
    }
};

// 构造函数还有分类
// 按照参数:
// 1. 无参构造, 也可以叫做默认构造函数
// 2. 有参构造

// 按照构造方法
// 1. 拷贝构造, 特点在于传入参数是一个(const classname &num)
// 2. 普通构造函数

void test01()
{

    // 调用构造函数也有几种方法
    // 1. 括号法
    person p1;// 这个显然就是默认构造
    // 但是需要注意, person p1();是一个不一样的情况
    person p4();// 在这里并不会认为是一个对象的创建, 而是一个函数的声明, 看起来也很像哦
    
    person p2(10, "nihao");
    person p3(p2);
    
    // 2. 显示法

    person p5 = person(66, "nihao");// 这个就是显示法调用一个显示对象
    person p6 = person(p2);// 这就是显示法构造出一个对象
    // 匿名对象
    person(55, "good");// 这样没有多变的情况, 那么这样的到的就是一个匿名构造函数, 匿名对象的话那么再创建之后就直接被析构了
    // 拷贝构造也是不能创建一个匿名对象的
    // person(p3);// 直接报错
    // 会认为是一个对象的声明, 那么再对于一个已经存在的对象, 就会出现重定义的情况
    
    // 3. 隐式转换法
    person p7 = {14, "nihao"};
    person p8 = p7;// 这个就是省略了调用函数, 感觉就是用来一个等号, 和中括号的用处, 直接赋值构造了

}


int main()
{
    test01();// 这个是在栈区, 也就是临时变量, 会进行构造还会析构
    // 所以先执行这个函数的话, 就会直接把这个参数解决掉

    // person p1;// 只是初始化了一下, 但是并没有调用函数, 就执行了一遍那个构造函数
    // 这个在全局变量里面的, 实际上在执行的时候只会调用构造函数, 只有当整个程序执行结束的时候才会调用析构函数, 也就是
    // 按任意键结束的时候 才会调用析构函数

    return 0;
}