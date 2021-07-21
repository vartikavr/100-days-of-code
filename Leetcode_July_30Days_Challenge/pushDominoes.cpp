//O(n) time, O(n) space

class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        int force=0, n= dominoes.length();
        int forces[n];
        for(int i=0;i<n;i++)
            forces[i]=0;
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R')
                force= n;
            else if(dominoes[i]=='L')
                force=0;
            else
                force = max(force-1, 0);
            forces[i]+= force;
        }
        force=0;
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='L')
                force= n;
            else if(dominoes[i]=='R')
                force= 0;
            else
                force= max(force-1, 0);
            forces[i]-= force;
        }
        for(int i=0;i<n;i++)
        {
            if(forces[i]>0)
                res+='R';
            else if(forces[i]<0)
                res+='L';
            else
                res+='.';
        }
        return res;
    }
};