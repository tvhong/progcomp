using System;

public class StringMerger
{
    public static bool isMerge(string s, string part1, string part2)
    {
        Console.WriteLine("{0}|{1}|{2}", s, part1, part2);
        Console.WriteLine("{0}|{1}|{2}", s.Length, part1.Length, part2.Length);
        if (s.Length != part1.Length + part2.Length)
            return false;

        char endingChar = Char.MaxValue;
        s = string.Format("{0}{1}{2}", s, endingChar, endingChar);
        part1 = string.Format("{0}{1}", part1, endingChar);
        part2 = string.Format("{0}{1}", part2, endingChar);

        int i, i1, i2, duplicateCount;
        i = i1 = i2 = duplicateCount = 0;
        while (i < s.Length && i1 < part1.Length && i2 < part2.Length)
        {
            Console.WriteLine("i = {0}, i1 = {1}, i2 = {2}, duplicateCount = {3}", i, i1, i2, duplicateCount);
            Console.WriteLine("{0}, {1}, {2}", s.Substring(i, s.Length - i),
                    part1.Substring(i1, part1.Length - i1),
                    part2.Substring(i2, part2.Length - i2));
            if (s[i] == part1[i1] && s[i] == part2[i2])
            {
                duplicateCount++;
                i++;
                i1++;
                i2++;
            }
            else if (s[i] == part1[i1])
            {
                i++;
                i1++;
                if (duplicateCount > 0)
                {
                    // trace back on part2
                    i2 -= duplicateCount;
                    duplicateCount = 0;
                }
            }
            else if (s[i] == part2[i2])
            {
                i++;
                i2++;
                if (duplicateCount > 0)
                {
                    // trace back on part1
                    i1 -= duplicateCount;
                    duplicateCount = 0;
                }
            }
            else if (duplicateCount > 0)
            {
                // 
                i2 -= duplicateCount;
                duplicateCount = 0;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
}
