using System;
namespace CodeForces {
    class Solve820A {
        int c, v0, v1, a, l;
        int days;

        public void readInput() {
            var parts = Console.ReadLine().Split(' ');
            this.c = int.Parse(parts[0]);
            this.v0 = int.Parse(parts[1]);
            this.v1 = int.Parse(parts[2]);
            this.a = int.Parse(parts[3]);
            this.l = int.Parse(parts[4]);
        }

        public void printAnswer() {
            Console.WriteLine(this.days);
        }

        public void solve() {
            this.days = 1;
            int pagesRead = this.v0;
            while (pagesRead < this.c) {
                int theoreticalSpeed = this.v0 - this.l + this.days * this.a;
                pagesRead += Math.Min(theoreticalSpeed, this.v1 - l);
                this.days++;
            }
        }
    }

    class Runner {
        public static void Main() {
            Solve820A solver = new Solve820A();
            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
