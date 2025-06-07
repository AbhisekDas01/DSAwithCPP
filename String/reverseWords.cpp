/**
 * Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseWordsStack(string s)
{

    stack<string> st;

    string temp = "";
    string ans = "";

    for (auto it : s)
    {

        if (it != ' ')
        {
            temp.push_back(it);
        }
        else
        {
            if (!temp.empty())
            {
                st.push(temp);
                temp = "";
            }
        }
    }

    if (!temp.empty())
    {
        st.push(temp);
        temp = "";
    }

    while (!st.empty())
    {

        ans += st.top();
        st.pop();
        ans.push_back(' ');
    }

    ans.pop_back();

    return ans;
}

int main()
{

    string str;
    cout << "Enter the string: ";

    getline(cin, str);

    cout << "String is : " << str << endl;

    str = reverseWordsStack(str);

    cout << "Reverse is : " << str;

    return 0;
}