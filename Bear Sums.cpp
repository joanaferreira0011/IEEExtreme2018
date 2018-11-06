#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
 /* 
    unsigned int numberCases,numberElements;
    int  sum, number;
    vector<int> numbersVector;
    cin >> numberCases;
    
    for(size_t cases = 0; cases< numberCases; cases++)
    {
        numbersVector.clear();
        cin >> sum >> numberElements;
        
        // Create vector with elements from user input"
        for(size_t i = 0; i< numberElements; i++)
        {
            cin >> number;
            numbersVector.push_back(number);
        }
        
        // Map the vector and check every sum 
        for(size_t index = 0; index<=numberElements; index++)
        {
            if(index== numberElements)
                {
                    cout << "!OK" <<endl;
                    break;
                }
            bool skip = false;
            for(size_t it = (index+1); it<(numberElements); it++)
            {
                int first = numbersVector.at(index);
                int second = numbersVector.at(it);
                if (first +second==sum)
                {
                    cout << min(first, second)<<" " << max(first,second) << endl;
                    skip = true;
                    break;
                }
            }
            if (skip) break;
        }
    }
} */

unsigned int numberCases,numberElements;
    int  sum, number;
    vector<int> numbersVector, possibleSums;
    cin >> numberCases;
    
    for(size_t cases = 0; cases< numberCases; cases++)
    {
        numbersVector.clear();
        possibleSums.clear();
        cin >> sum >> numberElements;
        
        /* Create vector with elements from user input"*/
        for(size_t i = 0; i< numberElements; i++)
        {
            cin >> number;
            numbersVector.push_back(number);
        }
        
        /* Map the vector and check every sum */
        for(size_t index = 0; index<=numberElements; index++)
        {
            if(index== numberElements)
                {
                    if(possibleSums.size()==0)
                    {cout << "!OK" <<endl;
                    break;}
                    else
                    {
                        size_t min = 0;
                        for(size_t a = 0; a< possibleSums.size(); a = a+3)
                        {
                            if(possibleSums.at(a)< possibleSums.at(min))
                            {
                                min = a;
                            }
                        }
                        cout<< possibleSums.at(min+1) << " "<< possibleSums.at(min+2) << endl;
                }
                }
    
            for(size_t it = (index+1); it<(numberElements); it++)
            {
                int first = numbersVector.at(index);
                int second = numbersVector.at(it);
                if (first +second==sum)
                {
                    possibleSums.push_back(max(it, index));
                    possibleSums.push_back(min(first, second));
                    possibleSums.push_back(max(first,second));
                  
                }
            }
            
        }
    }
}