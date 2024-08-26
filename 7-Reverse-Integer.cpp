class Solution {
public:
    string remove(const string& str) {
        size_t start = str.find_first_not_of('0');
        if (start == string::npos) {
            return \0\; 
        }
        return str.substr(start);
    }

    int reverse(int x) {
        bool sign = x < 0;
        string s = to_string(abs(x)); 
        std::reverse(s.begin(), s.end());
        s = remove(s);

        long reversed = stoll(s); 
        if (sign) {
            reversed = -reversed;
        }

        if (reversed < numeric_limits<int>::min() || reversed > numeric_limits<int>::max()) {
            return 0;
        }

        return static_cast<int>(reversed);
    }
};