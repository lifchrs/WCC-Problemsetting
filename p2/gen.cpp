#include "sol.h"

#include "testlib.h"

#include <iostream>

using namespace std;

string bruh(int n) {
  return to_string(1000 + n).substr(1);
}

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

vector < bool > anss = {
  1,
  0,
  1,
  0,
  1,
  0,
  0,
  1,
  1,
  0,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  0
};

int main(int argc, char * argv[]) {
  registerGen(argc, argv, 1);
  int tc = 1;
  ofstream file;

  cout << anss.size();

  while (tc <= 6) {
    file.open("in/input." + bruh(tc));
    int len;
    string s;
    if (anss[tc - 1]) {
      len = 2;
      s = rnd.next("[a-z]{" + to_string(len) + "}");
      s = s + rnd.next("[a-z]{1}") + rev(s);
      for (char & a: s) {
        if (rnd.next(0, 4) == 3) a = '*';
      }
    } else {
      len = 5;
      s = rnd.next("[a-z]{" + to_string(len) + "}");
      for (char & a: s) {
        cout << rnd.next(0,4);
        if (rnd.next(0, 4) == 1) a = '*';
      }
    }

    file << s;
    file.close();

    /* file.open("in/output." + bruh(tc)); */
    /* file << solve(s); */
    /* file.close(); */

    tc++;
  }
  while (tc <= 11) {
    file.open("in/input." + bruh(tc));
    int len = rnd.next(5, int(1e3) - 1);
    string s = rnd.next("[a-z]{" + to_string(len / 2) + "}");
    if (len % 2) {
      s = s + rnd.next("[a-z]{1}") + rev(s);
    } else {
      s += rev(s);
    }
    for (char & a: s) {
      if (rnd.next(0, 20) == 1) a = '*';
    }
    if (!anss[tc-1]) {
      for (char & a: s) {
        if (rnd.next(0, 20) == 3) a = ('a' + rnd.next(0, 25));
      }
    }

    file << s;
    file.close();

    /* file.open("in/output." + bruh(tc)); */
    /* file << solve(s); */
    /* file.close(); */

    tc++;
  }
  while (tc < 21) {
    file.open("in/input." + bruh(tc));
    int len = rnd.next(5, int(2e5));
    string s = rnd.next("[a-z]{" + to_string(len / 2) + "}");
    if (len % 2) {
      s = s + rnd.next("[a-z]{1}") + rev(s);
    } else {
      s += rev(s);
    }
    for (char & a: s) {
      if (rnd.next(0, 20) == 1) a = '*';
    }
    if (!anss[tc-1]) {
      for (char & a: s) {
        if (rnd.next(0, 20) == 1) a = ('a' + rnd.next(0, 25));
      }
    }

    file << s;
    file.close();

    /* file.open("in/output." + bruh(tc)); */
    /* file << solve(s); */
    /* /1* cout << solve(s); *1/ */
    /* file.close(); */

    tc++;
  }

}
