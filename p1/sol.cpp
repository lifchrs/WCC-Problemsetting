#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
   cin >> s;
   s = s.substr(0,min((int)s.size(),10*10*10));
    int cnt = 0;
    for(char c : s){
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                cnt++;
            }
    }
    cout << cnt;
}
