using System;
using System.Collections.Generic;
using System.IO;

namespace ReverseInteger {
    public class Program {
        public static void Main(string[] args) {
            Console.WriteLine(Program.Reverse(-2147483648));
        }
        
        //O(logx)
        public static int Reverse(int x) {
        	int res = 0;
        	int sign = 1;
        	Console.WriteLine(x);
        	if (x < 0) {
        		sign = -1;
        		x = x * -1;
        	}
			if (x == 0 || x == Int32.MinValue) {
				return 0;
			}
			Console.WriteLine(x);
			while(x >= 10) {
				Console.WriteLine(res);
				int last = x % 10;
				x = x / 10;
				res = res * 10 + last;
			}
			if (Int32.MaxValue/10 < res) {
				return 0;
			}
			else {
				return (res * 10 + x) * sign;
			}
    	}
    }
}
