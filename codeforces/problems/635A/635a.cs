using System;
using System.Linq;

class Codeforce635A
{
    static void Main()
    {
        string str = Console.ReadLine();
        var vals = str.Split().Select(Int32.Parse).ToArray();
        int r = vals[0];
        int c = vals[1];
        int n = vals[2];
        int k = vals[3];
        int[,] arr = new int[r, c];
        for (int i = 0; i < n; i++)
        {
            var tmp = Console.ReadLine().Split().Select(Int32.Parse).ToArray();
            int x = tmp[0] - 1, y = tmp[1] - 1;
            arr[x, y] = 1;
        }

        int[,,,] cnt = new int[r, c, r, c];

        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                for (int x = i; x < r; x++)
                {
                    for (int y = j; y < c; y++)
                    {
                        int tmp = arr[x, y];
                        if (x > i)
                        {
                            tmp += cnt[i, j, x - 1, y];
                        }
                        for (int h = j; h < y; h++)
                        {
                            tmp += arr[x, h];
                        }
                        cnt[i, j, x, y] = tmp;
                        if (tmp >= k)
                        {
                            ans++;
                        }
                        //Console.WriteLine("{0} {1} {2} {3} {4}", i, j, x, y, tmp);
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }
}
