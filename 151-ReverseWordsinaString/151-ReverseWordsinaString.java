// Last updated: 8/7/2026, 10:19:36 PM
1class Solution {
2    public String reverseWords(String s) {
3        s = s.trim();
4
5        String current = "";
6        String reverse = "";
7
8        int i = 0;
9
10        while (i < s.length()) {
11
12            if (s.charAt(i) != ' ') {
13                current += s.charAt(i);
14            }
15            else if (!current.isEmpty()) {
16                reverse = current + " " + reverse;
17                current = "";
18            }
19
20            i++;
21        }
22
23        if(!current.isEmpty()){
24            reverse = current + " " + reverse;
25        }
26        return reverse.trim();
27    }
28}