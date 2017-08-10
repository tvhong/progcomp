using System;
using System.Text;
using System.Diagnostics;
namespace CodeForces {
    class Solve792C {
        const int MAX_LENGTH = 100000;
        int n;
        int[] nums = new int[MAX_LENGTH + 5];
        int[,] k = new int[MAX_LENGTH, 3];
        bool[] isKept = new bool[MAX_LENGTH];
        bool hasZero = false;

        public void readInput() {
            string input = Console.ReadLine();
            this.n = input.Length;
            for (int i = 0; i < input.Length; i++) {
                this.nums[i] = input[i] - '0';
                if (this.nums[i] == 0) {
                    this.hasZero = true;
                }
            }
        }

        public void solve() {
            this.initK();
            this.buildK();
            this.buildAnswer();
        }

        private void initK() {
            for (int rem = 0; rem < 3; rem++) {
                if (rem == this.nums[0] % 3) {
                    k[0, rem] = 1;
                } else {
                    k[0, rem] = 0;
                }
            }
        }

        private void buildK() {
            for (int i = 1; i < this.n; i++) {
                for (int rem = 0; rem < 3; rem++) {
                    if (this.nums[i] == 0 && k[i-1, rem] == 0) {
                        // cannot keep this digit 0 because we have no non-zero digit before.
                        k[i, rem] = k[i-1, rem];
                        continue;
                    }

                    int scoreIfStartHere = (rem == this.nums[i] % 3) ? 1 : 0;

                    int compl = this.getCompliment(rem, this.nums[i]);
                    int scoreIfKeepThis = (k[i-1, compl] > 0) ? k[i-1, compl] + 1 : 0;

                    int scoreIfDiscardThis = k[i-1, rem];
                    k[i, rem] = Math.Max(scoreIfStartHere, scoreIfKeepThis);
                    k[i, rem] = Math.Max(k[i, rem], scoreIfDiscardThis);
                }
            }
        }

        private void buildAnswer() {
            if (k[this.n - 1, 0] == 0) {
                // no answer
                return;
            }

            int rem = 0;
            for (int i = this.n - 1; i > 0; i--) {
                if (k[i, rem] == k[i-1, rem]) {
                    this.isKept[i] = false;
                } else {
                    this.isKept[i] = true;

                    int compl = this.getCompliment(rem, this.nums[i]);
                    Debug.Assert(k[i, rem] == k[i-1, compl] + 1);

                    rem = compl; 
                }
            }

            if (rem == this.nums[0] % 3) {
                this.isKept[0] = true;
            }
        }

        private int getCompliment(int rem, int val) {
            return (rem+9 - val) % 3;
        }

        public void printAnswer() {
            // this.printK();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < this.n; i++) {
                if (this.isKept[i]) {
                    sb.Append(this.nums[i]);
                }
            }

            if (sb.Length == 0) {
                if (this.hasZero) {
                    sb.Append(0);
                } else {
                    sb.Append("-1");
                }
            }

            Console.WriteLine(sb.ToString());
        }

        private void printK() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < this.n; i++) {
                for (int rem = 0; rem < 3; rem++) {
                    sb.Append(k[i, rem]);
                }

                sb.Append(Environment.NewLine);
            }

            Console.WriteLine(sb.ToString());
        }
    }

    class Runner {
        public static void Main() {
            Solve792C solver = new Solve792C();
            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
