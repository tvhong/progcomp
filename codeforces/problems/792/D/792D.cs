using System;
using System.Collections.Generic;
namespace CodeForces {
    class Solve792D {
        ulong n, q, start, startLevel, dest, levelMax;
        string path;
        Dictionary<ulong, ulong> parent = new Dictionary<ulong, ulong>();

        public void solve() {
            this.readGeneralInput();

            for (ulong i = 0; i < this.q; i++) {
                this.readCaseInput();
                this.findAnswer();
                this.printAnswer();
            }
        }

        private void readGeneralInput() {
            var parts = Console.ReadLine().Split(' ');
            this.n = ulong.Parse(parts[0]);
            this.q = ulong.Parse(parts[1]);

            this.levelMax = this.log2(this.n + 1) - 1;
        }
        
        private void readCaseInput() {
            this.start = ulong.Parse(Console.ReadLine());
            this.path = Console.ReadLine();
        }

        private void findAnswer() {
            this.parent.Clear();
            this.traverseToStart();
            this.dest = this.followPath();
        }

        private ulong log2(ulong num) {
            num >>= 1;

            ulong result = 0;
            while (num > 0) {
                num >>= 1;
                result += 1;
            }

            return result;
        }

        private void traverseToStart() {
            ulong current = (this.n + 1) / 2;
            ulong currentLevel = 0;

            while (current != this.start) {
                Tuple<ulong, ulong> newPos;
                if (current < this.start) {
                    newPos = this.right(current, currentLevel);
                } else {
                    newPos = this.left(current, currentLevel);
                }

                current = newPos.Item1;
                currentLevel = newPos.Item2;
            }

            this.startLevel = currentLevel;
        }

        private ulong followPath() {
            ulong current = this.start;
            ulong currentLevel = this.startLevel;

            foreach (char operation in this.path) {
                Tuple<ulong, ulong> newPosition;
                if (operation == 'U') {
                    newPosition = this.up(current, currentLevel);
                } else if (operation == 'L') {
                    newPosition = this.left(current, currentLevel);
                } else {
                    newPosition = this.right(current, currentLevel);
                }

                current = newPosition.Item1;
                currentLevel = newPosition.Item2;
            }

            return current;
        }

        private Tuple<ulong, ulong> left(ulong num, ulong level) {
            return this.down(true, num, level);
        }

        private Tuple<ulong, ulong> right(ulong num, ulong level) {
            return this.down(false, num, level);
        }

        private Tuple<ulong, ulong> down(bool left, ulong num, ulong level) {
            if (level == this.levelMax) {
                return Tuple.Create(num, level);
            } else {
                ulong newNum = left ?
                    num - this.getDescendingDifference(level) :
                    num + this.getDescendingDifference(level);

                parent[newNum] = num;

                return Tuple.Create(newNum, level + 1);
            }
        }

        private ulong getDescendingDifference(ulong level) {
            return (this.n + 1) >> ((int)level + 2);
        }

        private Tuple<ulong, ulong> up(ulong num, ulong level) {
            ulong p;
            if (parent.TryGetValue(num, out p)) {
                return Tuple.Create(p, level - 1);
            } else {
                return Tuple.Create(num, level);
            }
        }

        private void printAnswer() {
            Console.WriteLine(this.dest);
        }
    }

    class Runner {
        public static void Main() {
            Solve792D solver = new Solve792D();
            solver.solve();
        }
    }
}
