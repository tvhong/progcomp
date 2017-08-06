using System;
using System.IO;
using System.Text;
namespace CodeForces {
    class Solve36B {
        const char WHITE = '.';
        const char BLACK = '*';
        int n, k;
        int paintingSize;
        string[] fractal;
        char[,] painting;

        public void readInput() {
            var lines = File.ReadAllLines("input.txt");
            var parts = lines[0].Split(' ');
            this.n = int.Parse(parts[0]);
            this.k = int.Parse(parts[1]);

            this.fractal = new string[n];
            for (int i = 0; i < n; i++) {
                fractal[i] = lines[1 + i];
            }

            this.paintingSize = this.power(n, k);

            this.painting = new char[this.paintingSize, this.paintingSize];
            for (int i = 0; i < this.paintingSize; i++) {
                for (int j = 0; j < this.paintingSize; j++) {
                    this.painting[i, j] = WHITE;
                }
            }
        }

        public void printAnswer() {
            var sb = new StringBuilder();
            for (int i = 0; i < this.paintingSize; i++) {
                for (int j = 0; j < this.paintingSize; j++) {
                    sb.Append(this.painting[i, j]);
                }
                if (i != this.paintingSize - 1) {
                    sb.Append(Environment.NewLine);
                }
            }

            //Console.WriteLine(sb.ToString());
            File.WriteAllText("output.txt", sb.ToString());
        }

        public void solve() {
            paintFractal(this.k, 0, 0);
        }

        private void paintFractal(int k, int top, int left) {
            if (k == 0) {
                return;
            }

            int squareSize = this.power(this.n, k-1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int topOnPainting = top + i*squareSize;
                    int leftOnPainting = left + j*squareSize;
                    if (this.fractal[i][j] == BLACK) {
                        this.paintSquare(topOnPainting, leftOnPainting, squareSize);
                    } else {
                        this.paintFractal(k-1, topOnPainting, leftOnPainting);
                    }
                }
            }
        }

        private void paintSquare(int top, int left, int squareSize) {
            for (int i = top; i < top + squareSize; i++) {
                for (int j = left; j < left + squareSize; j++) {
                    this.painting[i, j] = BLACK;
                }
            }
        }

        private int power(int b, int power) {
            int result = 1;
            for (int i = 0; i < power; i++) {
                result *= b;
            }

            return result;
        }
    }

    class Runner {
        public static void Main() {
            Solve36B solver = new Solve36B();
            solver.readInput();
            solver.solve();
            solver.printAnswer();
        }
    }
}
