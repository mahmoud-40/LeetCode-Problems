class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return compute(expression);
    }

private:
    unordered_map<string, vector<int>> memo;

    vector<int> compute(const string& expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> results;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResults = compute(left);
                vector<int> rightResults = compute(right);

                for (int l : leftResults) {
                    for (int r : rightResults) {
                        int result = 0;
                        if (c == '+') {
                            result = l + r;
                        } else if (c == '-') {
                            result = l - r;
                        } else if (c == '*') {
                            result = l * r;
                        }
                        results.push_back(result);
                    }
                }
            }
        }

        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        memo[expression] = results;
        return results;
    }
};
