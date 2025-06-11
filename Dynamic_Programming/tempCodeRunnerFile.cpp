
// State ->   dp[i][j] = the length of the longest common subsequence 
//            between text1[0...i-1] and text2[0...j-1]

// Transition ->
//            1->  if(text1[i]==text2[j])
//            2->   if(text1[i]!=text2[j])
