using System;
namespace CodeForces {
    class Solve834B {
        const int MAX_GUESTS = 1000000 + 5;
        int n, k;
        string gates;
        int[] openTimes;
        int[] closeTimes;
        int maxOpenGatesCount = 0;

        public void readInput() {
            var parts = Console.ReadLine().Split(' ');
            this.n = int.Parse(parts[0]);
            this.k = int.Parse(parts[1]);
            this.gates = Console.ReadLine();
        }

        public void printAnswer() {
            string unguarded = this.k < this.maxOpenGatesCount ? "YES" : "NO";
            Console.WriteLine(unguarded);
        }

        public void solve() {
            getOpenCloseTimes();
            getMaxOpenGates();
        }

        private void getOpenCloseTimes() {
            this.openTimes = new int[26];
            this.closeTimes = new int[26];

            for (int i = 0; i < 26; i++) {
                this.openTimes[i] = -1;
                this.closeTimes[i] = -1;
            }

            for (int i = 0; i < this.gates.Length; i++) {
                int gateNum = convertGateToNum(this.gates[i]);
                if (this.openTimes[gateNum] == -1) {
                    this.openTimes[gateNum] = i;
                }

                this.closeTimes[gateNum] = i;
            }
        }

        private int convertGateToNum(char gate) {
            return (int)gate - (int)'A';
        }

        private void getMaxOpenGates() {
            for (int i = 0; i < this.n; i++) {
                int openGatesCount = 0;
                for (int gateNum = 0; gateNum < 26; gateNum++) {
                    if (this.isGateOpen(gateNum, i)) {
                        openGatesCount++;
                    }
                }

                if (openGatesCount > maxOpenGatesCount) {
                    this.maxOpenGatesCount = openGatesCount;
                }
            }
        }

        private bool isGateOpen(int gateNum, int time) {
            return this.openTimes[gateNum] <= time && time <= this.closeTimes[gateNum];
        }
    }

    class Runner {
        public static void Main() {
            Solve834B solver = new Solve834B();

            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
