#include <iostream>
#include <algorithm>
using namespace std;

int op1[25];
// bool st[25];

int main()
{
    int idx = 0;
    string op;
    while(cin >> op)
    {       
        if(op[0] == 'o')
            op1[idx++] = 3;
        else if(op[0] == 'a')
            op1[idx++] = 2;
        else if(op[0] == 't')
            op1[idx++] = 1;
        else if(op[0] == 'f')
            op1[idx++] = 0;
        else if(op[0] == 'n')
            op1[idx++] = 4;
    }

    for(int i = 0 ; i < idx - 1 ; i ++)
    {
        // cout << op1[i] << " ";
        if((op1[i] == 1 || op1[i] == 0) && (op1[i+1] == 0 || op1[i+1] == 1))
        {
            cout << "error" << endl;
            return 0;
        }
    }
   for(int j = 0 ; j < idx ; j ++){
        for(int i = 0 ; i < idx ; i ++)
        {
            if(op1[i] == 4 /*&& !st[i]*/)
            {
                op1[i + 1] = (op1[i+1] + 1) % 2;
                for(int m = i ; m <= idx ; m ++)
                {
                    swap(op1[m], op1[m + 1]);
//                     swap(st[m], st[m+1]);
                }
                idx --;
//                 st[i] = true;
            }
            // cout<< "idx : " << idx << " " << endl;
        }
    }

    // for(int i = 0 ; i < idx ; i ++)
    // {
    //     cout << op1[i] << " ";
    // }
    
    for(int j = 0 ; j < idx ; j ++)
    {
        for(int i = 0 ; i < idx ; i ++)
        {
            if(op1[i] == 2/* && !st[i]*/)
            {
                //是and并且没有用过
                op1[i - 1] = op1[i - 1] & op1[i + 1];
                for(int m = i  ; m <= idx ; m ++)
                {
                    swap(op1[m], op1[m + 1]);
//                     swap(st[m], st[m+1]);
                }
                idx--;
                for(int m = i  ; m <= idx ; m ++)
                {
                    swap(op1[m], op1[m + 1]);
//                     swap(st[m], st[m+1]);
                }
                idx--;
            }
            // cout<< "idx : " << idx << " " << endl;
        }
    }

    // for(int i = 0 ; i < idx ; i ++)
    // {
    //     cout << op1[i] << " ";
    // }
    
    for(int j = 0 ; j < idx ; j ++)
    {
        for(int i = 0 ; i < idx ; i ++)
        {
            if(op1[i] == 3 /*&& !st[i]*/)
            {
                //是and并且没有用过
                op1[i - 1] = op1[i - 1] ^ op1[i + 1];
                for(int m = i; m <= idx ; m ++)
                {
                    swap(op1[m], op1[m + 1]);
//                     swap(st[m], st[m+1]);
                }
                idx--;
                for(int m = i ; m <= idx ; m ++)
                {
                    swap(op1[m], op1[m + 1]);
//                     swap(st[m], st[m+1]);
                }
                idx--;
            }
        }
    }
    // cout << endl;
    // for(int i = 0 ; i < idx ; i ++)
    // {
    //     cout << op1[i] << " ";
    // }
    
    if(op1[0] == 1) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}