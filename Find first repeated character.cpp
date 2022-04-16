to find the character that occurs more than once and whose index of second occurrence is smallest. S contains only lowercase letters.

 

Example 1:

Input: S="geeksforgeeks"
Output: e
Explanation: 'e' repeats at third position.
 

Example 2:

Input: S="hellogeeks"
Output: l
Explanation: 'l' repeats at third position.
 

Example 3:

Input: S="abc"
Output: -1
Explanation: There is no repeated character.
  
  Codes Are:-
    String firstRepChar(String s) 
    { 
        HashSet<Character> set = new HashSet<>();
        
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(set.add(ch))
              continue;
              
            return ch+"";
        }
        
        return "-1";
    }
