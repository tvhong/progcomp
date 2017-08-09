using System;
using System.Text;
namespace CodeForces {
    class Solve792C {
        string num;
        bool[] isDiscarded;
        bool anyZeroDiscarded = false;

        int mod1Cnt = 0;
        int[] mod1Positions = new int[3];

        int mod2Cnt = 0;
        int[] mod2Positions = new int[3];

        public void readInput() {
            this.num = Console.ReadLine();
            this.isDiscarded = new bool[this.num.Length];
        }

        public void solve() {
            for (int i = 0; i < this.num.Length; i++) {
                int val = this.num[i] - '0';
                int mod = val % 3;
                if (mod == 1) {
                    this.mod1Positions[this.mod1Cnt++] = i;
                    if (this.mod1Cnt == 3) {
                        this.mod1Cnt = 0;
                    }
                } else if (mod == 2) {
                    this.mod2Positions[this.mod2Cnt++] = i;
                    if (this.mod2Cnt == 3) {
                        this.mod2Cnt = 0;
                    }
                }
            }

            discardDigits();
            cleanupZeros();
        }

        private void discardDigits() {
            int startIdx = Math.Min(this.mod1Cnt, this.mod2Cnt);
            for (int i = startIdx; i < this.mod1Cnt; i++) {
                this.isDiscarded[this.mod1Positions[i]] = true;
            }

            for (int i = startIdx; i < this.mod2Cnt; i++) {
                this.isDiscarded[this.mod2Positions[i]] = true;
            }
        }

        private void cleanupZeros() {
            for (int i = 0; i < this.num.Length; i++) {
                if (!this.isDiscarded[i]) {
                    if (this.num[i] == '0') {
                        this.isDiscarded[i] = true;
                        this.anyZeroDiscarded = true;
                    } else {
                        break;
                    }
                }
            }
        }

        public void printAnswer() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < this.num.Length; i++) {
                if (!this.isDiscarded[i]) {
                    sb.Append(this.num[i]);
                }
            }

            if (sb.Length == 0) {
                if (this.anyZeroDiscarded) {
                    sb.Append('0');
                } else {
                    sb.Append("-1");
                }
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
