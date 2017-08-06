using System;
using System.IO;
namespace CodeForces {
    class Solve36A {
        int n;
        string signals;
        bool isIntelligence;

        public void readInput() {
            var lines = File.ReadAllLines("input.txt");
            this.n = int.Parse(lines[0]);
            this.signals = lines[1];
        }

        public void printAnswer() {
            File.WriteAllText("output.txt", this.isIntelligence ? "YES" : "NO");
        }

        public void solve() {
            this.isIntelligence = true;
            int lastSignalIndex = -1;
            int signalSpacing = -1;
            for (int i = 0; i < this.signals.Length; i++) {
                if (this.signals[i] == '1') {
                    if (lastSignalIndex != -1) {
                        if (signalSpacing == -1) {
                            signalSpacing = i - lastSignalIndex;
                        }

                        if (signalSpacing != i - lastSignalIndex) {
                            this.isIntelligence = false;
                            break;
                        }
                    }

                    lastSignalIndex = i;
                }
            }
        }
    }

    class Runner {
        public static void Main() {
            Solve36A solver = new Solve36A();
            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
