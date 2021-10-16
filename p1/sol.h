#include <bits/stdc++.h>
using namespace std;
int solve(string s){
    int cnt = 0;
    for(char c : s){
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                cnt++;
            }
    }
    return cnt;
}
