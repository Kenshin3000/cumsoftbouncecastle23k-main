//C# 'Hello, world'
//Rextester.Program.Main is the entry point for your code. Don't change it.

using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var nums = new[]{1,2,3,4};
            var sum = nums.Aggregate( (a,b) => a + b);
            Console.WriteLine(sum);
            
            var chars = new []{"a","b","c", "d"};
            var csv = chars.Aggregate(new StringBuilder(), (a,b) => {
                if(a.Length>0)
                    a.Append(",");
                a.Append(b);
                return a;
            });
            Console.WriteLine(csv);
            
            var multipliers = new []{10,20,30,40};
            var multiplied = multipliers.Aggregate(5, (a,b) => a * b);
            
            
            // hgfhghg hg h 
            
            
            Console.WriteLine(multiplied);
            
            Console.Write(true);
                
        }
    }
}
