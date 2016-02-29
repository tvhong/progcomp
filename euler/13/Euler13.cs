using System;
using System.Linq;
using System.Numerics;

class Euler13
{
    public static void Main()
    {
        BigInteger result = new BigInteger();
        for (int i = 0; i < 100; i++)
        {
            string str = Console.ReadLine();
            BigInteger num = BigInteger.Parse(str);
            result = BigInteger.Add(result, num);
            Console.WriteLine(result.ToString());
        }
        var str_result = result.ToString();
        for (int i = 0; i < 10; i++)
        {
            Console.Write(str_result[i]);
        }
        Console.WriteLine();
    }
}