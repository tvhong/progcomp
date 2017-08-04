using System;

class AB {
    int numOfAs;
    int numOfBs;

    public string createString(int n, int k) {
        this.calculateNumOfAsAndBs(n, k);
        if (this.numOfAs == 0 && this.numOfBs == 0) {
            return string.Empty;
        }
        
        string result;
        try {
            result = this.generateString(n, k, this.numOfAs);
        } catch (Exception) {
            result = string.Empty;
        }

        return result;
    }
    
    void calculateNumOfAsAndBs(int n, int k) {
        for (int a = 0; a <= n; a++) {
            if (k <= this.calculateMaxScore(n, a)) {
                this.numOfAs = a;
                this.numOfBs = n - a;
                break;
            }
        }
    }

    int calculateMaxScore(int n, int numOfAs) {
        return (n - numOfAs) * numOfAs;
    }
    
    string generateString(int n, int k, int a) {
        if (n == 0) {
            if (k > 0) {
                throw new Exception("Cannot generate string");
            }

            return "";
        }

        if (a == 0) {
            return new string('B', n);
        }

        int scoreWithAHere = n - a;
        if (scoreWithAHere <= k) {
            return "A" + this.generateString(n - 1, k - scoreWithAHere, a - 1);
        } else  {
            return "B" + this.generateString(n - 1, k, a);
        }
    }
}
