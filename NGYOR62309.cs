//Rextester.Program.Main is the entry point for your code. Don't change it.
//Compiler version 4.0.30319.17929 for Microsoft (R) .NET Framework 4.5

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        class tup
        {
            public tup (int one, int two)
            {
                Item1 = one;
                Item2 = two;
            }
            public int Item1 {get;set;}
            public int Item2 {get;set;}
        }
        
        class tupComparer : IEqualityComparer<tup>
        {
            public bool Equals(tup tup1, tup tup2)
            {
                if (tup1 == null && tup2 == null) { return true;}
                if (tup1 == null | tup2 == null) { return false;}
                if (tup1.Item1 == tup2.Item1 && tup1.Item2 == tup2.Item2) { return true; }
                return false;
            }
            public int GetHashCode(tup t)
            {
                string code = t.Item1+","+t.Item2;
                return code.GetHashCode();
            }
        }
        
        public static void Main(string[] args)
        {
            //Your code goes here
           HashSet<tup> hs = new HashSet<tup>(new tupComparer());
            tup tup1 = new tup(1,2);
           tup tup2 = new tup(1,2);
            hs.Add(tup1);
            hs.Add(tup2);
            
            foreach(tup e in hs)
            {
                Console.WriteLine(e.Item1 +" "+e.Item2);
            }      
            
            
        }
    }
}
