#include <iostream>

using namespace std;

void snt(int n, bool mark[]){
    int a = 2; 
    while (true){
        int p = a*a;
        if(p>n) break;
        while(p <= n){
            mark[p] = true;
            p += a;
        }
        a++;
        while(a<=n && mark[a]) a++;
        if (a>n) break;
    }
}
int greatestCommonPrimeDivisor(int a, int b)
{
    bool mark[100];
    snt(min(a, b), mark);
    int d = 0;
    for (int i = min(a, b); i >= 2; i--)
        if (mark[i] == false && a % i == 0 && b % i == 0)
            return i;
    return -1;
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << greatestCommonPrimeDivisor(a,b) << endl;
    return 0;
}
