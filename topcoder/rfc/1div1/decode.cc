#include <string>
#include <vector>
class BinaryCode {
  public:
    decode (string q) {
        //q += '0';
        int yes, i;
        vector<string> res;
        for (j=0; j<=1; j++) {
            string p;
            p.resize(q.size());
            yes = 1;
            p[0] = j;
            for (i = 1; i<q.size(); i++) {
                p[i] = q[i-1] - p[i-1];
                p[i] -= (i>=2) ? p[i-2] : 0;
                if (p[i] > 1) {
                    yes = 0;
                    break;
                }
            }
            if (yes)
                res[j] = p;
            else 
                res[j] = "NONE";
            }
            return res;
    }
}
