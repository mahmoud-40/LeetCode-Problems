class Solution {
public:
bool isLiftBracket(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}
bool isRightBracket(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}
bool BracketMatch(char lift, char right)
{
    return (right == ')' && lift != '(') ||
           (right == ']' && lift != '[') ||
           (right == '}' && lift != '{');
}

bool isValid(string s)
{
    stack<char> stk;
    for (char ch : s)
    {
        if (isLiftBracket(ch))
        {
            stk.push(ch);
        }
        if (isRightBracket(ch))
        {
            if (stk.empty())
            {
                return false;
            }
            char top = stk.top();
            stk.pop();
            if (BracketMatch(top, ch))
            {
                return false;
            }
        }
    }
    return stk.empty();
}
};