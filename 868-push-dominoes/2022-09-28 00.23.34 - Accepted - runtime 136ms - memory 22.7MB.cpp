class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
		vector<int> L(n,INT_MAX);
		vector<int> R(n,INT_MAX);
		
		if(s[n-1]=='L')
			L[n-1]=0;
		for(int i=n-2;i>=0;i--)
		{
			if(s[i]=='R')
				continue;    // This is because if there exists any dominoe to the right pushing to the left,
					      	// our current (i'th) dominoe cancels it with a right force of its own
			if(s[i]=='L')
				L[i]=0;
			else if(L[i+1]!=INT_MAX)
				L[i]=1+L[i+1];
		}
		
		if(s[0]=='R')
			R[0]=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='L')
				continue;   // This is because if there exists any dominoe to the left pushing to the right,
				      	  // our current (i'th) dominoe cancels it with a left force of its own
			if(s[i]=='R')
				R[i]=0;
			else if(R[i-1]!=INT_MAX)
				R[i]=1+R[i-1];
		}
		
		string ans="";
		for(int i=0;i<n;i++)
		{
            // The dominoe faces both forces at equal times, or never faces a force from either side (i.e. L[i]=R[i]=INT_MAX)
			if(L[i]==R[i]) ans+=".";
			else if(L[i]<R[i]) ans+="L";
			else ans+="R";
		}
		return ans;
    }
};