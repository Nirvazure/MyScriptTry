// 链接：https://www.nowcoder.com/questionTerminal/7615ed51b7b94b9eadf0776146b4e23c
// 来源：华为
// 思路：利用KMP的nexts数组的思想，求出最小周期是多少

import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string = scanner.next();
        char[] pattern = string.toCharArray();
        int n = pattern.length;
        int[] nexts = new int[n];
        nexts[0] = 0;
        int i = 1;
        int len = 0;
        while(i < n) {
            if(pattern[i] == pattern[len]) {
                len++;
                nexts[i] = len;
                i++;
            }
            else {
                if(len > 0) len = nexts[len - 1];
                else {
                    nexts[i] = len;
                    i++;
                }
            }
        }
        if(n % (n - nexts[n - 1]) == 0)
            System.out.println(n - nexts[n - 1]);
        else System.out.println(n);
    }
}