#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define GAP ('a' - 'A')
using namespace std;

string str;
int arms, legs;
bool none(int i) {
  if (i+1 >= str.length()) return false;
  return (abs(str[i] - str[i+1]) == GAP);
}

bool arm(int i) {
  if (i+1 >= str.length()) return false;
  return (str[i] == str[i+1]);
}

bool leg(int i) {
  if (i+3 >= str.length()) return false;
  return ((abs(str[i] - str[i+2]) == GAP) && (abs(str[i+1] - str[i+3]) == GAP));
}

bool scan() {
  bool del = false;
  int i = 0;
  while (i<str.length()) {
    if (none(i)) {
      str.erase(i, 2);
      del = true;
    } else if (arm(i)) {
      arms++;
      str.erase(i, 2);
      del = true;
    } else if (leg(i)) {
      legs++;
      str.erase(i, 4);
      del = true;
    } else {
      i++;
    }
  }
  return del;
}

string inverse(string s) {
  string res;
  for (int i = s.length()-1; i>=0; i--) {
    if (s[i] >= 'a' && s[i] <='z') res.push_back(s[i] - GAP);
    else res.push_back(s[i] + GAP);
  }
  return res;
}

void randomcut() {
  // chose 1 char
  int i = 0;
  int j;
  for (j = 1; j<str.length(); j++) {
    if (str[j] == str[i] || abs(str[j] - str[i]) == GAP)
      break;
  }
  int b1 = rand() % j;
  int b2 = rand() % (str.length() - j) + j;

  string s1(str, b2+1, str.length() - b2);
  string s2(str, 1, b1);
  string s3(str, b1+1, j-b1-1);
  string s4(str, j+1, b2-j);
  /*
  cout << "i=0; j=" << j << "; b1=" << b1 << "; b2=" << b2 << endl;
  cout << "s1 = " << s1 << endl;
  cout << "s2 = " << s2 << endl;
  cout << "s3 = " << s3 << endl;
  cout << "s4 = " << s4 << endl;
  */
  string newstr;
  if (str[i] == str[j]) {
    newstr = s2 + str.substr(i, 1) + s1 +
             inverse(s3) + str.substr(j, 1) + inverse(s4);
  } else {
    if (str[i] > str[j]) { // lowercase first
      newstr = s2 + str.substr(i, 1) + s1 +
               s4 + str.substr(j, 1) + s3;
    } else {
      newstr = s4 + str.substr(j, 1) + s3 +
               s2 + str.substr(i, 1) + s1;
    }
  }
  str = newstr;
  //cout << "newstr = " << newstr << endl << endl;
}

int main() {
  while (cin >> str, str != "END") {
    arms = legs = 0;
    while (str.length() > 0) {
      //cout << "str = " << str << endl;
      while (scan());
      if (str.length() > 0) {
        randomcut();
      }
    }
    if (arms && legs) {
      arms += legs*2;
      legs = 0;
    }
    if (arms) {
      cout << arms << " arm";
      if (arms > 1) cout << "s";
      cout << endl;
    } else if (legs) {
      cout << legs << " leg";
      if (legs > 1) cout << "s";
      cout << endl;
    } else {
      cout << "none" << endl;
    }
  }
  return 0;
}
