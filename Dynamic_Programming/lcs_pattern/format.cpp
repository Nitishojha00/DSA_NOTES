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
