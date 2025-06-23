// Base condition -> Initializition
I have to initialize first row and first column 

// double for loop
// same logic
// according to question we use operator
if(arr[i-1] <= j) 
{
    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
}
else
{
   dp[i][j] = dp[i-1][j];
}