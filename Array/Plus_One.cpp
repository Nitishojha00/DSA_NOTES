// without understanding i have done lot of wrong submission -> leetcode easy rpoblem 
//   You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.


    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // no carry needed
                return digits;
            }
            digits[i] = 0;      // set to 0 and carry to next
        }
        // if we reached here, all digits were 9 → need one more digit
        digits.insert(digits.begin(), 1);
        return digits;
    }