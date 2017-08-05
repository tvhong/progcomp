using System;
namespace CodeForces {
    class Solve834B {
        public void solve() {
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++) {
                var parts = Console.ReadLine().Split(' ');
                int a = int.Parse(parts[0]);
                int b = int.Parse(parts[1]);
                //Console.WriteLine(string.Format("{0}, {1}", a, b));


            }
            
        }
    }

    class Runner {
        public static void Main() {
            Solve834B solver = new Solve834B();
            solver.solve();
        }
    }
}
