using System;
namespace CodeForces {
    class Solve792A {
        int n;
        int[] locs;
        int minDist = Int32.MaxValue;
        int cnt;

        public void readInput() {
            this.n = int.Parse(Console.ReadLine());

            var nums = Console.ReadLine().Split(' ');

            this.locs = new int[this.n];
            for (int i = 0; i < n; i++) {
              this.locs[i] = int.Parse(nums[i]);
            }
        }

        public void printAnswer() {
            Console.WriteLine(string.Format("{0} {1}", this.minDist, this.cnt));
        }

        public void solve() {
            Array.Sort(this.locs);

            for (int i = 1; i < this.locs.Length; i++) {
                int dist = this.locs[i] - this.locs[i-1];
                if (dist == this.minDist) {
                    this.cnt += 1;
                } else if (dist < this.minDist) {
                    this.minDist = dist;
                    this.cnt = 1;
                }
            }
        }
    }

    class Runner {
        public static void Main() {
            Solve792A solver = new Solve792A();
            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
