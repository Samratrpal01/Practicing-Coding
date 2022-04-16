Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3

Codes Are:-
   int romanToDecimal(string &str) {
      map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      int val=0;
      int pre=INT_MAX;
      for(auto i=0;i<str.size();i++)
      {
        if(mp[str[i]]>=mp[str[i+1]])
        {
            val+=mp[str[i]];
        }
        
        else
            val-=mp[str[i]];
      }
      
      return val;
    }
