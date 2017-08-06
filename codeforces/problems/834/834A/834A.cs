using System;
namespace CodeForces {
    class Solve834A {
        private static char[] chars = {'v', '<', '^', '>'};

        private static int GetIntRepresentation(char c) {
            for (int i = 0; i < chars.Length; i++) {
                if (chars[i] == c) {
                    return i;
                }
            }

            throw new Exception("Invalid spin char");
        }

        private static bool isClockwise(int start, int end, int seconds) {
            for (int i = 0; i < seconds; i++) {
                start = (start + 1) % 4;
            }

            return start == end;
        }

        private static bool isCounterClockwise(int start, int end, int seconds) {
            for (int i = 0; i < seconds; i++) {
                end = (end + 1) % 4;
            }

            return start == end;
        }

        public static void Main() {
            var input = Console.ReadLine();
            var parts = input.Split(' ');
            int start = GetIntRepresentation(parts[0][0]);
            int end = GetIntRepresentation(parts[1][0]);
            // Console.WriteLine(string.Format("start = {0}, end={1}", start, end));

            input = Console.ReadLine();
            int seconds = int.Parse(input);
            seconds = seconds % 4;

            bool cw = isClockwise(start, end, seconds);
            bool ccw = isCounterClockwise(start, end, seconds);
            if (cw && ccw) {
                Console.WriteLine("undefined");
            } else if (cw) {
                Console.WriteLine("cw");
            } else {
                Console.WriteLine("ccw");
            }
        }
    }
}
