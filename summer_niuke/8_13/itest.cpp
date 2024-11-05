#include <iostream>
#include <cmath>
#include <vector>
#include <string>

// 判断是否为完全平方数
bool isPerfectSquare(int x) {
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}

// 查找并打印区间 [L, R] 中所有符合条件的数字
void findAndPrintValidNumbers(int L, int R) {
    int count = 0;
    std::vector<int> validNumbers;

    // 遍历区间 [L, R] 中的所有数字
    for (int num = L; num <= R; ++num) {
        std::string str_num = std::to_string(num);
        int n = str_num.size();

        // 如果位数不是偶数，则不符合题意，跳过
        if (n % 2 != 0) continue;

        // 将数字分为两部分
        int left_part = std::stoi(str_num.substr(0, n / 2));
        int right_part = std::stoi(str_num.substr(n / 2, n / 2));

        // 检查两部分是否都是完全平方数
        if (isPerfectSquare(left_part) && isPerfectSquare(right_part)) {
            count++;
            validNumbers.push_back(num);
        }
    }

    // 输出符合条件的数字个数
    std::cout << "Total count: " << count << std::endl;

    // 输出所有符合条件的数字
    std::cout << "Valid numbers: ";
    for (int num : validNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int L = 1025;
    int R = 9936;
    std::cin >> L >> R;
    findAndPrintValidNumbers(L, R);

    return 0;
}