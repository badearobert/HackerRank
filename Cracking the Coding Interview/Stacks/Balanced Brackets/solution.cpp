#include <stack>
#include <iostream>
using namespace std;

const int BRACKETS_SIZE = 3;

const char OPENING_BRACKETS[BRACKETS_SIZE] = { '(', '[', '{' };
const char CLOSING_BRACKETS[BRACKETS_SIZE] = { ')', ']', '}' };

bool isOpenBracket(char c)
{
    for (int i = 0 ; i < BRACKETS_SIZE; ++i) {
        if (c == OPENING_BRACKETS[i]) 
            return true; 
    }
    
    return false;
}
bool isClosedBracket(char c)
{
    for (int i = 0 ; i < BRACKETS_SIZE; ++i) {
        if (c == CLOSING_BRACKETS[i]) 
            return true; 
    }
    
    return false;
}

bool bracketsMatch(char first, char second) { 
    for (int i = 0 ; i < BRACKETS_SIZE; ++i) {
        if (first == OPENING_BRACKETS[i] && second == CLOSING_BRACKETS[i]) {
            return true;
        }
    }
    return false;
} 

bool is_balanced(string expression) {
    stack<char> st;
    for (int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (isOpenBracket(c))
        {
            st.push(c);
        }
        else if (isClosedBracket(c) && false == st.empty())
        {
            const char top = st.top();
            if (bracketsMatch(top, c))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
