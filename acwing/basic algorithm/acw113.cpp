#include <iostream>
#include <vector>

using namespace std;
// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
    public:
        vector<int> specialSort(int N) {
                // 插入排序, 加二分排序
        // 我们先准备一个要插入的数, 然后二分正在处理的数组, 因为这个数组是满足左边的数大于右边的数的
        // 所以我们要找到一个点, 这个点小于要插入的点
        // 所以二分找到一个点, 这个点比我们要插入的数要大, 然后他的左边一定有一个值比这个值小

        // 如果左边这个值比插入的值要大的话, 那再继续找左边r = mid - 1, 如果要小的话那么答案就可以是l = mid

        vector<int> res;
        res.push_back(1);
        // 先枚举要插入的数
        for(int i = 2 ; i <= N ; i ++)
        {
            int l = 0, r = res.size() - 1; // 这个是res里面的数的下标也就是二分res里面的数
            while(l <r)
            {
                int mid = l + r + 1 >> 1;
                if(compare(res[mid], i))
                    // 如果小于的话, 那么就看右边
                    l = mid;
                else
                    // 如果是大于的话那么看左边
                    r = mid - 1;
            }
            // 找到了这个小于他的数的话, 那么直接换到这个位置的后面就行
            res.push_back(i);
            for(int j = res.size() - 1 ; j  >= r + 2 ; j -- )
                // 从末尾换到第r个下标, 末尾的下标是res.size() - 1 
                swap(res[j], res[j - 1]);
            // 但是如果当前这个数组中全都大于这个数的话, 那么他就应该被换到第一个位置了
            if(compare(i, res[r])) swap(res[r], res[r + 1]);// 当前i就在res[r+1]的位置上, 因为所有的数都大于i, 所以r就是第一个位置, 也就是是0

        }
        return res;
    }
};

// 这是一道交互提