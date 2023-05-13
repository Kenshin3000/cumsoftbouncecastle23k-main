/Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //Your code goes here
            var x = 3;
            var y = 4;
            var z =5;
            if ((x-1) > 2)
            {
                y=y+1; 
            }
            else                
            {
                y=y-1;
                z=x+y;
            }
            for (int i = 1; i < 9; i++)
            {
                y=y+1;
                z=z+y;
            }
            Console.WriteLine("X = "+x+", Y = "+y+", Z = "+z+"");
        }
    }
}
