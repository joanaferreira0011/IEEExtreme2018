#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int steps = 0;

bool areNumbersDifferent(map<int,int> * numbers) {
    bool different = true;
    map<int,int>::iterator it;
    for (it = (*numbers).begin(); it != (*numbers).end(); it++) {
        if ((*it).second > 1) different = false;
    }
    return different;
}

int main() {
    int N;
    cin >> N;
    
    map<int, int> numbers;
    int average = 0;
    for (int i = 0; i < N ; i++) {
        int a;
        cin >> a;
        average+=a;
        numbers[a]++;
    }
    average = average/N;
    
    // map<int,int>::iterator it;
    // for (it = numbers.begin(); it != numbers.end(); it++) {
    //     cout << (*it).first << " : " << (*it).second << endl;
    // }
    
    int top = average, bottom = average;
    while(1) {
        if (numbers[top] > 1) {
            numbers[top]--;
            numbers[top+1] ++;
            steps++;
        }
        if (areNumbersDifferent(&numbers)) break;
        if (numbers[top] == 1) top++;
        
        if (numbers[bottom] > 1) {
            numbers[bottom]--;
            numbers[bottom-1] ++;
            steps++;
        }
        if (areNumbersDifferent(&numbers)) break;
        if (numbers[bottom] == 1) bottom--;
    }
    
    cout << steps << endl;
    return 0;
}