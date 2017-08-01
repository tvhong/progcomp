using System;
namespace CodeForces {
    class Solve834B {
        int n, k;
        string guests;

        public void readInput() {
            var parts = Console.ReadLine().Split(' ');
            this.n = int.Parse(parts[0]);
            this.k = int.Parse(parts[1]);
            this.guests = Console.ReadLine();
        }

        public void printAnswer() {
            Console.WriteLine(this.n);
            Console.WriteLine(this.k);
            Console.WriteLine(this.guests);
        }

        public void solve() {
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
