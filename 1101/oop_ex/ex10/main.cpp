#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2;
    while(cin >> a1 >> a2){
        try{
            if(a1 < 0 || a2 < 0) throw "Bad Arguments: a1 < 0, a2 < 0 not allowed!";
            double ans = sqrt(a1) * sqrt(a2);
            cout << "Geometric mean of " << a1 << " and " << a2 << " is ";
            if(floor(ans) == ceil(ans)){
                cout << fixed << setprecision(0) << ans << endl;
            }else{
                cout << fixed << setprecision(2) << ans << endl;
            }
        }
        catch(const char* err){
            cout << err << endl;
        }
        try{
            if(a1 + a2 == 0) throw "Bad Arguments: a1 = -a2 not allowed!";
            double ans = (2 * a1 * a2) / (double)(a1 + a2);
            cout << "Harmonic mean of " << a1 << " and " << a2 << " is ";
            if(floor(ans) == ceil(ans)){
                cout << fixed << setprecision(0) << ans << endl;
            }else{
                cout << fixed << setprecision(2) << ans << endl;
            }
        }
        catch(const char* err){
            cout << err << endl;
        }
    }
}