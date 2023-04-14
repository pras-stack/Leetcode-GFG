class Solution {
public:
    int longestPalindromeSubseq(string b) {
        string a = b;
        reverse(b.begin() , b.end());
        int n = a.size();
        if(n==0 or n==1){
            return 1;
        }
        int t[n+1][n+1];
        
        for(int i=0 ; i<n+1 ; i++){
            for(int j=0 ; j<n+1 ; j++){
                if(i==0 or j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1 ; i<n+1 ; i++){
            for(int j=1 ; j<n+1 ; j++){
                if(a[i-1]==b[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        
        return t[n][n];
    }
};