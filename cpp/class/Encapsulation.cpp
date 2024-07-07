#include <iostream>
#include <string>
using namespace std;

class Circle{
    // 这个就是类的基本
    
    // 类里面有
    // 访问权限
    // 属性
    // 行为
public:
    const double Pi = 3.14;
    int r;// 半径
    Circle(int tmp_r)
    {
        this->r = tmp_r;
    }
    double get_c()
    {
        return 2 * Pi * r;
    }
};

// 一个学生类
class Stu{

    // 类中的属性和行为都叫做成员
    // 属性 也是成员属性, 成员变量
    // 行为 也是成员方法, 成员函数
public:
    string Name;
    int id;

    void showinfo()
    {
        cout << "name : " << Name << " id : " << id << endl;
    }// 一个空参构造

    Stu(string name, int id)
    {
        this->Name = name;
        this->id = id;
    }

    // 通过行为进行操作
    void set_name(string name)
    {
        Name = name;
    }
    void set_id(int id)
    {
        this->id = id;// 如果重名了的话, 还是用this吧
    }

};

// 封装的第二层含义
// 在设计类的时候, 使用不同的权限

// 公共权限         成员类内可以访问, 类外可以访问
// 保护权限         成员类内可以访问, 类外不可以访问(主要在继承中, 子类可以访问父类的成员)
// 私有权限         成员类内可以访问, 类外不可以访问(子类不可以访问父类的成员)

class Person{

public:
    string Name;

protected:
    string car;

private:
    int passport;

public:
    Person(string name, string car_name, int pass)
    {
        Name = name;
        car = car_name;
        passport = pass;
    }// 函数内部都是可以访问的到的

};

// 成员属性设置为私有的重要性
// 1. 可以自己控制读写的权限
// 2. 对于写可以检测数据的有效性
class Animal{

private:
    string m_name;

    int m_age;// 控制这个数据的有效性
    // 比如控制年龄是在0 ~ 150之间


    string m_idol;

public:
    void set_Name(string name)
    {
        m_name = name;
    }

    string get_name()
    {
        return m_name;
    }
    // 其他属性同样

    bool set_age(int age)
    {
        if(age < 0 || age > 150)
        {
            cout << "年龄: " << age << ", 输出年龄有误, 赋值失败" << endl;
            return false;;
        }
        m_age = age;// 否则就可以成功赋值
        return true;
    }

    int get_age()
    {
        return m_age;
    }


};

// 在封装的过程中, 我们也可以为了防止代码太长了
// 把每一个类封装到一个单独的文件中
// 然后再使用的时候只需要引用头文件就可以了
// 头文件就是 .h 文件, 这个文件中不包括方法的实现, 只包括声明, 实际上就是在这个文件中创建的类
// 然后在一个 .cpp文件中实现.h中的所有方法, 这里的话只是按照方法的实现就行, 不需要实现类


int main()
{
    Circle c1(10);// 创造一个对象, 调用了一个参数的构造函数

    // c1.r = 10;

    cout << "圆的周长是 : " << c1.get_c() << endl;

    Stu s1("你好", 19);
    s1.set_id(91);
    cout << "这个学生的名字是 : " << s1.Name << " 这个学生的id是 : " << s1.id << endl;

    Person p1("你好", "好车", 110);// 实例化了一个对象
    
    p1.Name = "不好";
    // p1.car = "坏车";// 保护权限
    // p1.passport = 119;// 私有权限
    // 以下两行都会直接报错, 因为都是在类外都是不可以访问到的

    // -------------------------------------------------------------

    Animal dog;

    dog.set_Name("nihao");
    cout << "狗的名字叫做: " <<dog.get_name() << endl;

    if(dog.set_age(110)){
        cout << "狗子的年龄是: " << dog.get_age() << endl;
    }
    return 0;
}