using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BLab_13
{
    class Program
    {
        static List<string> get_sp_words(string alpab, int len)
        {
            List<string> sp_words = new List<string>((int)Math.Pow(4, len));
            get_sp_words(ref sp_words, alpab, len, "");
            return sp_words;
        }

        static void get_sp_words(ref List<string> sp_words, string alpab, int len, string p)
        {
            if (len == 0)
            {
                sp_words.Add(p);
            }
            else
                foreach (char c in alpab)
                {
                    get_sp_words(ref sp_words, alpab, len - 1, p + c);
                }
        }

        static int c_disc(string a, string b)
        { 
             int count = 0; 
             int len = a.Length; 
 
             for (int i = 0; i < len; i++) 
             { 
                 if (a[i] != b[i]) 
                 { 
                     count++; 
                 } 
             } 
 
             return count; 
        }
        
        static int d(string pat, string text)
        { 
             int len = text.Length; 
             int k = pat.Length; 
 
             List<int> distance = new List<int>(); 
 
 
             for (int i = 0; i < len - k + 1; i++) 
             { 
                 distance.Add(c_disc(pat, text.Substring(i, k))); 
             } 
 
             return distance.Min(); 
        }
        
        static int d_dna_t(string pat, string[] dna)
        { 
             int sum = 0; 
 
             foreach (string dnait in dna) 
             { 
                 sum += d(pat, dnait); 
             } 
 
             return sum; 
        }
        
        static string MedianString(string[] dna, int k)
        { 
             int dist = int.MaxValue; 
             string median = ""; 
             List<string> allKm = get_sp_words("AGCT", k); 
 
 
             foreach (string km in allKm) 
             { 
                 if (dist > d_dna_t(km, dna)) 
                 { 
                     dist = d_dna_t(km, dna); 
                     median = km; 
                 } 
             } 

             return median; 
        } 

        static void Main(string[] args)
        { 
             int k = int.Parse(Console.ReadLine()); 
 
             string buffer = ""; 
             while (true) 
             { 
                 string s = Console.ReadLine(); 
                 if (string.IsNullOrEmpty(s)) 
                     break; 
 
                 buffer += s + ' '; 
             } 
 
 
             string[] dna = buffer.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries); 
      
             Console.WriteLine(MedianString(dna, k)); 
             Console.ReadKey(); 
         } 
    }
}
