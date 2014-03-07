#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BinaryCode {
  private:
    string guess(string code, int p0) {
      const char* q = code.c_str();
      cout << q << endl;
      char p[55];
      bool possible = true;
      p[0] = p0;
      for (size_t i = 1; i < code.length(); i++) {
        if (i < 2)
          p[i] = (q[i-1]-'0') - p[i-1];
        else 
          p[i] = (q[i-1]-'0') - p[i-1] - p[i-2];
        cout << "p[" << i << "] = " << (int)p[i] << endl;
        if (p[i] > 1 || p[i] < 0) possible = false;
      }
      if (possible) {
        for (size_t i = 0; i < code.length(); i++)
          p[i] += '0';
        p[code.size()] = '\0';
        return string(p);
      } else {
        return "NONE";
      }
    }
    
  public:
    vector<string> decode(string message) {
      vector<string> res;
      if (message.size() == 1) {
        if (message[0] == '0')
          res.push_back("0"), res.push_back("NONE");
        else if (message[0] == '1')
          res.push_back("NONE"), res.push_back("1");
        else
          res.push_back("NONE"), res.push_back("NONE");
      } else {
        res.push_back(guess(message, 0));
        res.push_back(guess(message, 1));
      }

      return res;
    }
};
