// Given two strings text1 and text2, 
// return the length of their longest common subsequence. 
// If there is no common subsequence, return 0.

// A subsequence of a string is a new string
//  generated from the original string with some 
//  characters (can be none) deleted without changing the 
//  relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a 
// subsequence that is common to both strings that is ace.


// State ->   dp[i][j] = the length of the longest common subsequence 
//            between text1[0...i-1] and text2[0...j-1]

// Transition ->
//            1->  if(text1[i]==text2[j])
//            2->   if(text1[i]!=text2[j])

           // okay itna to samjh arha ✅✅✅

           // okay ready for implementation
           
           #include<bits/stdc++.h>
           using namespace std;
           
           int lcs(string &s1 , string &s2) 
           {
                int n = s1.size(), m = s2.size(); 
                vector<int> dp(m + 1, 0);

                for (int i = 1; i <= n; i++) 
                {
                    int prev = 0;  // Represents dp[i-1][j-1]
                    for (int j = 1; j <= m; j++) 
                    {
                         int temp = dp[j];  // Save current dp[j] before it's updated
                            if (s1[i - 1] == s2[j - 1]) 
                                dp[j] = prev + 1;
                            else 
                                dp[j] = max(dp[j - 1], dp[j]);
                        
                         prev = temp;  // Update prev for next iteration
                    }
                }

                return dp[m];
          }

            int main()
            {
                string s = "abc" , t = "aebdc";
                 int val = lcs(s,t);
                 cout<<val;
                 return 0;
            }
