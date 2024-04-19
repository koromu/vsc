#include <iostream>
#include <vector>

using namespace std;
const int N = 1010;
bool isMirror;
vector<int> pre(N);//存原元素
vector<int> post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;//从根节点右边开始找
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;//在右边界之前找到第一个大于等于根节点下标, 这个点下标对应的点就是这个根的右子树的根, 因为右子树的值都比根节点的值大或者相等吧
        while(j > root && pre[root] <= pre[j]) j--;//在根节点之前找到最后一个小于根节点的下标, 这个点下标对应的点就是这个根的左子树的根, 因为左子树的值都比根节点的值小
    } else {//在镜像二叉树中, 性质变成了, 左子树元素都是大于等于根节点的, 右子树元素都是小于根节点的, 根据这个性质, 找到两个子树的边界
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;//对于一个根节点, 在剩余的节点中, 找到左右子树的根节点, 其中这两节点分界点一定是左边的全都是小于等于根节点, 右边的全都是大于根节点, 而我们的i和j就是移动到这个分界点的两侧, 相差一定是等于1的, 如果不是等于1, 这个子树中出现了不是符合前序遍历规则的序列, 说明这个可能不是一个二叉树, 可以直接return
    getpost(root + 1, j);//然后优先递归处理左子树, 左子树的根节点是root + 1, 直到最后一个小于父节点的点, 这些点都是左子树中的节点, 然后递归处理这些节点
    getpost(i, tail);//后序遍历讲的就是一个先左再右在中间, 然后处理右子树, 右节点的根节点就是第一个第一个大于等于父节点的点, 然后到最后一个节点, 都是右节点的数
    post.push_back(pre[root]);//如果这些节点已经全部分配给了左子树和右子树, 此时遍历一个左子树, 然后到左子树中没有剩余的左子树和右子树了, 然后就存入数组退出来了, 然后是右子树. 然后再退出这一层, 到了上一层, 上一层中也是刚刚给把左子树递归出来, 然后递归右子树, 假设右子树已经递归完了, 此时才会存下这个节点, 也就是先左后右最后中间的后序遍历
}//所以最后这个数组中是存的这个二叉树的后序遍历序列, 然后可以根据元素个数判断是否是一个先序遍历的二叉树, 因为在判断中先序遍历的顺序中是可以找到两个子树的边界的, 因为每次都是找到了这两个子树的边界, 所以如果找错了的话, 会提前return, 导致最后点的数量不对. 找错了的话也就说这个可能不是先序遍历得到二叉树, 所有的都是更具二叉树搜索树的性质来判断的
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pre[i];
    getpost(0, n - 1);//以下标0为根节点, 下标n-1的元素为可能是右边节点或左边节点的右边界
    if(post.size() != n) {//出来以后如果post中元素的数量是n, 说明是二叉树
        isMirror = true;///否则可能是镜像二叉树
        post.clear();
        getpost(0, n - 1);//再做一遍镜像二叉树的
    }
    if(post.size() == n) {//再看能不能构成一个镜像二叉树
        printf("YES\n%d", post[0]);//可以的话打印数组, 注意这个末尾不能有空格, 所以空格在元素前面, 然后第一个元素单独打印
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}