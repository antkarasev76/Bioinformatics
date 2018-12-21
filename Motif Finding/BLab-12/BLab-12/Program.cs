using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BLab_12
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

         static bool is_val_mut(string orig, string rep, int count_m)
         { 
             int len = orig.Length;
             int mismat = 0;
            
             for (int i = 0; i<len; i++) 
             { 
                 if (orig[i] != rep[i]) 
                 { 
                     mismat++; 
                 } 
                 if (mismat > count_m) 
                 { 
                     return false; 
                 } 
             } 
 
 
             return true; 
         } 

         static List<string> get_kd_mod(string km, int count_m)
         { 
             string alpab = "AGCT"; 
             List<string> patterns = new List<string>(); 
 
             foreach (var it in get_sp_words(alpab, km.Length)) 
             { 
                 if (is_val_mut(it.ToString(), km, count_m)) 
                 { 
                     patterns.Add(it.ToString()); 
                 } 
             } 

             return patterns; 
         } 
 
 
         static void Main(string[] args)
         { 
             string[] tok = Console.ReadLine().Split(' '); 
             int k = int.Parse(tok[0]); 
             int d = int.Parse(tok[1]); 
 
 
             string buffer = ""; 
             while (true) 
             { 
                 string s = Console.ReadLine(); 
                 if (string.IsNullOrEmpty(s)) 
                     break; 
 
                 buffer += s + ' '; 
             } 
 
 
             string[] dna_tab = buffer.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray(); 
 
 
             List<string> patterns = new List<string>(); 
 
 
             foreach (string str in dna_tab) 
             { 
                 int len = str.Length; 
                 for (int i = 0; i < len - k + 1; i++) 
                 { 
                     string km = str.Substring(i, k); 
 
                     foreach (string pattern in get_kd_mod(km, d)) 
                     { 
                         int count = 0;
                        
                         foreach (string subst in dna_tab) 
                         { 
                             for (int j = 0; j< len - k + 1; j++) 
                             { 
                                 if (is_val_mut(subst.Substring(j, k), pattern, d)) 
                                 { 
                                     count++; 
                                     break; 
                                 } 
                             } 
                         } 
 
 
                         if (count == dna_tab.Length) 
                         { 
                             patterns.Add(pattern); 
                         } 
                     } 
                 } 
             } 
 
             patterns = patterns.Distinct().ToList(); 
 
             Console.WriteLine(string.Join(" ", patterns)); 
             Console.ReadKey(); 
         } 

    }
}
