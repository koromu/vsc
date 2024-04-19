#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
    {
        ll Na, Nb, Sa = 0, Sb = 0, t1, t2;
        cin >> Na >> Nb;
        t1 = Na, t2 = Nb;
        while(t1) Sa += t1 % 10, t1 /= 10;
        while(t2) Sb += t2 % 10, t2 /= 10;
//        cout << "sa : " << Sa << " sb : " << Sb << endl;
        if(Na % Sb == 0 && Nb % Sa != 0) cout << 'A' << endl;
        else if(Na % Sb != 0 && Nb % Sa == 0) cout << 'B' << endl;
        else (Na > Nb ? cout << 'A' << endl : cout << 'B' << endl); 
    }
    
return 0;
}