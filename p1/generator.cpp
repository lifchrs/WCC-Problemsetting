#include "testlib.h"
#include <iostream>
#include "sol.h"

using namespace std;

string bruh(int n){
  return to_string(1000+n).substr(1);
}

int main(int argc, char* argv[]){
 registerGen(argc, argv, 1);
 int tc = 2;
 ofstream file;


 while(tc <= 4){
   file.open("in/input." + bruh(tc));
   int len = 5;
   string s = rnd.next("[a-z]{" + bruh(len) + "}");
   file << s;
   file.close();

   file.open("in/output." + bruh(tc));
   file << solve(s);
   file.close();

   tc++;
 }
 while(tc <= 9){

   file.open("in/input." + bruh(tc));
   int len = rnd.next(5,int(1e3)-1);
   string s = rnd.next("[a-z]{" + bruh(len) + "}");
   file << s;
   file.close();

   file.open("in/output." + bruh(tc));
   file << solve(s);
   file.close();
   tc++;
 }
while(tc < 21){
  file.open("in/input." + bruh(tc));
  int len = rnd.next(1,int(1e5)-1);
  string s = rnd.next("[a-z]{" + bruh(len) + "}");
  file << s;
  file.close();
   file.open("in/output." + bruh(tc));
   file << solve(s);
   file.close();
   tc++;

}
}
