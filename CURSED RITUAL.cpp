In order to perform a cursed ritual, Itadori Yuji needs to collect the cursed numbers with which he will be able to perform his jujutsu technique: “BLACK FLASH”. He asked his Sensei "Gojo Sotaru" to help him find these numbers in order to harness it's energy.
Cursed Numbers are positive integers whose decimal representation contains only the cursed digits 4 and 7. For example, numbers 47, 744, 4 are cursed and 5, 17, 467 are not. Itadori calls a number almost cursed if it could be evenly divided by some cursed number. Help him find out if the given number n is almost cursed.

Input Format
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output Format
In the only line, print "CURSED" (without the quotes), if number n is almost cursed. Otherwise, print "NOT CURSED" (without the quotes).

Constraints
1≤n≤1000
Sample Input 1 
 47
Sample Output 1 
 CURSED
Explanation
47 is almost cursed as it has both 4 and 7 as their only digits.

Sample Input 2 
 16
Sample Output 2 
 CURSED
void r(vector<int> &v , int n)
{
    if(n>1000)
        return;
    if(n)
    v.push_back(n);
    r(v , n*10+4);
    r(v, n*10+7);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> temp;
	r(temp,0);
	int  k ,f=0;
	cin>>k;
	for(auto j: temp)
	    if(k%j == 0 )
	    {
	        f = 1;
	        cout<<"CURSED";
	        break;
	    }
    if(!f)
        cout<<"NOT CURSED";
    cout<<"\n";
	return 0;
}

Codes are:-
  void pre(vector<int>&v,int n)
{
  if(n>10000)
    return;
  if(n)
    v.push_back(n);
  pre(v,n*10+4);
  pre(v,n*10+7);
}
int main()
{
  int n;
  cin>>n;
  for(auto i=0;i<v.size();i++)
  {
    if(k%j==0)
    {
      flag=1;
      cout<<"CURSED"<<endl;
      break;
    }
  }
  if(flag==0)
    cout<<"NOT CURSED";
}
