#include <bits/stdc++.h>
#include "testlib.h"
#include <iostream>
/* #include "sol.h" */

using namespace std;

string bruh(int n){
  return to_string(1000+n).substr(1);
}


int main(int argc, char* argv[]){

 registerGen(argc, argv, 0);

 int tc = 2;
 ofstream file;
 while(tc <= 4){
   map<pair<int,int>,bool> ma;
   file.open("in/input." + bruh(tc));
   int n = rnd.next(2,int(1e5));
   int m = rnd.next(1,int(2e5));
   int x = 1; //rnd.next(1,n);
   for(int i = 1; i <= n; i++) ma[{i,i}] = 1;
   file << n << " " << m << " " << x << endl;
   for(int i = 0; i < m; i++){
     int a,b,c;
     c=1;
     a = rnd.next(1,n);
     b = rnd.next(1,n);
     if(ma[{a,b}] == 1){
       i--;
       continue;
     }
     file << a << " " << b << " " << 1 << endl;
     ma[{a,b}] = 1;
   }
   set<int> done;
   for(int i = 0; i < x; i++){
     int currSize = done.size();
     int next = rnd.next(1,n);
     done.insert(next);
     if(currSize == done.size()) i--;
     else file << next << endl;
   }
   file.close();
   tc++;
 }

 while(tc <= 9){
   map<pair<int,int>,bool> ma;
   file.open("in/input." + bruh(tc));
   int n = rnd.next(2,int(1e5));
   int m = rnd.next(1,int(2e5));
   int x = rnd.next(1,n);
   for(int i = 1; i <= n; i++) ma[{i,i}] = 1;
   file << n << " " << m << " " << x << endl;
   for(int i = 0; i < m; i++){
     int a,b,c;
     c=1;
     a = rnd.next(1,n);
     b = rnd.next(1,n);
     if(ma[{a,b}] == 1){
       i--;
       continue;
     }
     file << a << " " << b << " " << 1 << endl;
     ma[{a,b}] = 1;
   }
   set<int> done;
   for(int i = 0; i < x; i++){
     int currSize = done.size();
     int next = rnd.next(1,n);
     done.insert(next);
     if(currSize == done.size()) i--;
     else file << next << endl;
   }
   file.close();
   tc++;
 }
while(tc < 21){
   map<pair<int,int>,bool> ma;
   file.open("in/input." + bruh(tc));
   int n = rnd.next(2,int(1e5));
   int m = rnd.next(1,int(2e5));
   int x = rnd.next(1,n);
   for(int i = 1; i <= n; i++) ma[{i,i}] = 1;
   file << n << " " << m << " " << x << endl;
   for(int i = 0; i < m; i++){
     int a,b,c;
     a = rnd.next(1,n);
     b = rnd.next(1,n);
     if(ma[{a,b}] == 1){
       i--;
       continue;
     }
     file << a << " " << b << " " << rnd.next(int(1e7),int(1e9)) << endl;
     ma[{a,b}] = 1;
   }
   set<int> done;
   for(int i = 0; i < x; i++){
     int currSize = done.size();
     int next = rnd.next(1,n);
     done.insert(next);
     if(currSize == done.size()) i--;
     else file << next << endl;
   }
   file.close();
   tc++;
}

}
