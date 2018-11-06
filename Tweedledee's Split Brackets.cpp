#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string brackets;
    bool openRoundBracket =false, openSquareBracket =false;
    cin >> brackets;
    
    for(size_t i = 0; i< brackets.length(); i++)
    {
        char bracket = brackets.at(i);
        switch(bracket){
            case '(':
            {
                if(openRoundBracket == false)
                {
                    brackets[i]= '2';
                    openRoundBracket = true;
                }
                else
                {
                    brackets[i]='1';
                }
                break;
            }
            
            case ')':
            {
                if(openRoundBracket == false)
                {
                    brackets[i]= '1';
                }
                else
                {
                    brackets[i]='2';
                }
                break;
            }
            
             case ']':
            {
                if(openSquareBracket == false)
                {
                    brackets[i]= '1';
                }
                else
                {
                    brackets[i]='2';
                }
                break;
            }
            
            case '[':
            {
                if(openSquareBracket == false)
                {
                    brackets[i]= '2';
                    openSquareBracket = true;
                }
                else
                {
                    brackets[i]='1';
                }
                break;
            }
        }  
    }
    size_t number1 = std::count(brackets.begin(), brackets.end(), '1');
    size_t number2 = std::count(brackets.begin(), brackets.end(), '2');
    
    if (number1%2==0 && number2%2==0)
    {
    for(size_t j = 0; j< brackets.length(); j++)
    {
        cout << brackets.at(j) << " ";
    }
    }
    else 
    cout << "impossible";
}