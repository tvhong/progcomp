using System;
using System.Collections.Generic;

class Euler14
{
    public static void Main()
    {
        const int LIMIT = 1000000;
        const int MAX = LIMIT + 5;
        int[] length = new int[MAX];
        int maxlen = 0, ans = 0;
        Queue<int> q = new Queue<int>();
        q.Enqueue(2);
        length[2] = 1;
        while (q.Count > 0)
        {
            int num = q.Dequeue();
            //Console.WriteLine("Num = {0}", num);

            if (length[num] > maxlen)
            {
                ans = num;
            }
            int newNum;
            if ((num - 1) % 3 == 0)
            {
                newNum = (num - 1) / 3;
                if (newNum % 2 != 0)
                    CheckAndEnqueNewNum(length, q, num, newNum);
            }
            newNum = 2 * num;
            if (newNum % 2 == 0)
                CheckAndEnqueNewNum(length, q, num, newNum);
        }
        Console.WriteLine("ans = {0}, length[ans] = {1}", ans, length[ans]);
    }
    
    private static void CheckAndEnqueNewNum(int[] length, Queue<int> q, int num, int newNum)
    {
        if (newNum > 1 && newNum < 1000000 && length[newNum] < length[num] + 1)
        {
            //Console.WriteLine("NewNum = {0}", newNum);
            if (length[newNum] > 0 && length[newNum] < length[num] + 1)
            {
                Console.WriteLine("ERROR: repeat number!!!");
                throw new Exception("Shit happened");
            }
            q.Enqueue(newNum);
            length[newNum] = length[num] + 1;
        }
    }
}