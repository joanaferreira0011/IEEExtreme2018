/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct star{
    int id, start, end, desire;
};

int isStarInVector(vector<star*> possibleStars, int ide)
{
    for(size_t i = 0; i< possibleStars.size(); i++)
    {
        if(possibleStars.at(i)->id == ide)
            return i;
    
    }
    return -1;
}

int main() {
    unsigned int N, desirability=0, negdesire=0;
    vector<star*> allstars, possibleStars, unusedStars;
    cin >>N;
    int maxTime = 0;
    for(unsigned int i=0; i<N; i++ )
    {
        star *s1 = new star;
        (*s1).id= i;
        cin >> (*s1).start >> (*s1).end >> (*s1).desire;
        if ((*s1).end > maxTime) maxTime = (*s1).end;
        allstars.push_back(s1);
    }
    

        for(size_t it = 0; it< allstars.size(); it++)
        {
           star currentStar =  *allstars.at(it);
           int currentStart = allstars.at(it)->start;
           int currentEnd = allstars.at(it)->end;
           int currentDesirability = allstars.at(it)->desire;
           //bool priority = true;
           
           for(size_t index= (it + 1); index<=allstars.size(); index++)
           {
             
               int newStart = allstars.at(index)->start;
               int newEnd = allstars.at(index)->end;
               if((newStart >= currentStart && newStart < currentEnd) || (newEnd > currentStart && newEnd <= currentEnd))
                {
                    
                    if(allstars.at(index)->desire > currentDesirability)
                   { 
                        //possibleStars.push_back(allstars.at(index));
                        currentStar = *allstars.at(index);
                        unusedStars.push_back(allstars.at(it));
                        //priority = false;
                       
                   }
                    
                    
                }
           }
           

           possibleStars.push_back(&currentStar);
        }
    
   
    for(size_t j=0; j<possibleStars.size(); j++)
    {desirability += possibleStars.at(j)->desire;}
    
    for(size_t ca=0; ca<unusedStars.size(); ca++)
    {negdesire += unusedStars.at(ca)->desire;}
    
    cout<< desirability-negdesire;
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct star{
    int id, start, end, desire;
};

int isStarInVector(vector<star*> possibleStars, int ide)
{
    for(size_t i = 0; i< possibleStars.size(); i++)
    {
        if(possibleStars.at(i)->id == ide)
            return i;
    
    }
    return -1;
}


int main() {
    unsigned int N, desirability=0, negdesire=0;
    vector<star*> allstars, possibleStars, unusedStars;
    cin >>N;
    int maxTime = 0;
    for(unsigned int i=0; i<N; i++ )
    {
        star *s1 = new star;
        (*s1).id= i;
        cin >> (*s1).start >> (*s1).end >> (*s1).desire;
        if ((*s1).end > maxTime) maxTime = (*s1).end;
        allstars.push_back(s1);
    }
 
    

        for(size_t it = 0; it< allstars.size(); it++)
        {
           star currentStar =  *allstars.at(it);
           int currentStart = allstars.at(it)->start;
           int currentEnd = allstars.at(it)->end;
           int currentDesirability = allstars.at(it)->desire;
           for(size_t index= (it + 1); index<allstars.size(); index++)
           {
               int newStart = allstars.at(index)->start;
               int newEnd = allstars.at(index)->end;
               if((newStart >= currentStart && newStart < currentEnd) || (newEnd > currentStart && newEnd <= currentEnd))
                {
                    if(allstars.at(index)->desire > currentDesirability)
                   { currentStar = *allstars.at(index);
                    unusedStars.push_back(allstars.at(it));}
                    
                    
                }
           }
         
           possibleStars.push_back(&currentStar);
        }
    
    
    for(size_t j=0; j<possibleStars.size(); j++)
    {desirability += possibleStars.at(j)->desire;}
    
    for(size_t ca=0; ca<unusedStars.size(); ca++)
    {negdesire += unusedStars.at(ca)->desire;}
    
    cout<< desirability-negdesire;
}
