class Solution {
public:
    bool isPalindrome(string s) {
        string ostr = "";
        
        // 1. Clean the string: keep only letters/numbers and force lowercase
        for (char ch : s) {
            if (isalnum(ch)) {
                ostr += tolower(ch);
            }
        }
        
        // 2. Your exact optimal two-pointer logic
        int i = 0;
        int j = ostr.size() - 1;
        
        while (i < j) {
            if (ostr[i] != ostr[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};