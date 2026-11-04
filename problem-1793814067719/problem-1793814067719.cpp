// Last updated: 11/4/2026, 11:11:07 PM
1class Solution {
2public:
3    string simplifyPath(string path) {
4        vector<string> st; // Also can use stack here I want
5        stringstream ss(path);
6        string dir;
7
8        while (getline(ss, dir, '/')) {
9            if (dir == "" || dir == ".") continue;
10            
11            if (dir == "..") {
12                if (!st.empty()) st.pop_back();
13            } else {
14                st.push_back(dir);
15            }
16        }
17        
18        string result = "";
19        for (const string& s : st) {
20            result += "/" + s;
21        }
22        
23        return result.empty() ? "/" : result;
24    }
25};
26
27/*
28
29My Approach Time Limit Exceediing
30
31class Solution {
32public:
33    string simplifyPath(string path) {
34        int n = path.size();
35        stack<char> st;
36        int count = 1;
37        string result = "";
38
39        for(int i=0; i<n; i++){
40            if(!st.empty() && st.top() == '/' && path[i] == '/') continue;
41            else if(!st.empty() && st.top() == '.' && path[i] == '.'){
42                count++;
43                i++;
44                while(path[i] == '.'){
45                    count++;
46                    i++;
47                }
48                i--;
49
50                if(count > 2){
51                    while(count){
52                        st.push('.');
53                    }
54                }
55                else{
56                    while(!st.empty() && st.top() != '/'){
57                        st.pop();
58                    }
59                }
60            }
61
62            st.push(path[i]);
63        }
64
65        while(!st.empty()){
66            result.insert(result.begin(), st.top());
67            st.pop();
68        }
69
70        return result;
71    }
72};
73
74*/