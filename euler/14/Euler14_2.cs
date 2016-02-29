using System;
using System.Collections.Generic;

class Euler14_2
{
    const int Limit = 1000000;
    private static Stack<int> st = new Stack<int>();
    private static Dictionary<int, int> length = new Dictionary<int, int>();
    private static int max = 0;
    private static int ans = 0;
    public static void Main()
    {
        length[1] = 1;
        for (int i = Limit - 1; i >= 1; i--)
        {
            if (Solve(i) > max)
            {
                max = Solve(i);
                ans = i;
            }
        }
        Console.WriteLine(ans);
    }

    private static int Solve(int n)
    {
        if (length.ContainsKey(n)) return length[n];
        int val = ((n % 2 == 0) ? Solve(n / 2) : Solve(3 * n + 1)) + 1;
        length.Add(n, val);
        return length[n];
    }
}