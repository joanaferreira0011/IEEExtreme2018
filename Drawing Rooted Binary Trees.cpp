#include <iostream>
#include <string>
using namespace std;


int main() {
    string vertical, horizontal;
    
    while (getline(cin, horizontal)) {
        getline(cin, vertical);
    
        size_t i =0;
        
        while(i < vertical.size())
        {
            size_t number_spaces = horizontal.find(vertical[i]);
            for(size_t i=1; i<=number_spaces; i++)
                cout<< " ";
            cout<< vertical[i] << endl;
            i++;
            
        }
    }
        
}