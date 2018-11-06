#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printGuess(vector<bool> &guess)
{
    cout << "Q";
        for(unsigned int i = 0; i < guess.size(); i++)
            cout << " " << guess.at(i);
        cout << endl;
        cout.flush();
    
}

void printAnswer(vector<bool> &guess)
{
    cout << "A";
        for(unsigned int i = 0; i < guess.size(); i++)
            cout << " " << guess.at(i);
        cout << endl;
        cout.flush();
    
}


int main() {
    unsigned int N, numberOfzeros, numberOfCorrectBits;
    cin>> N;
    vector<bool> guess (N, 0);
    

    printGuess(guess);
    cin >> numberOfzeros;
    numberOfCorrectBits = numberOfzeros;
    

    unsigned int new_numberOfCorrectBits, numberOfChanges =0;
    

    for(unsigned int index =0; index< guess.size() && numberOfChanges <= N-numberOfzeros; index++)
    {
        
        guess.at(index) = 1;
        printGuess(guess);
        cin >>new_numberOfCorrectBits;
        if(new_numberOfCorrectBits < numberOfCorrectBits)
            guess.at(index)=0;
        else
            {numberOfChanges ++;
            numberOfCorrectBits=new_numberOfCorrectBits;}
    }

    
    printAnswer(guess);
}