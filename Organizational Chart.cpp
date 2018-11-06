#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct divisionS {
    string name;
    divisionS * mother;
    vector<divisionS*> childs;
    int size1;
    int size2;
};

int main() {
    int N, Q;
    
    //input
    
    cin >> N >> Q;
    
    vector<divisionS> divs (N);
    string s;
    
    // Read cin N lines
    for (int i = 0; i < N; i++) {
        cin >> divs[i].name;
        cin >> s;
        
        if (s == "NONE") divs[i].mother = NULL;
        else {
            for (unsigned j = 0; j < divs.size(); j++) {
                if (divs.at(j).name == s) {
                    divs[i].mother = &(divs.at(j));
                    divs.at(j).childs.push_back(&divs[i]);
                }
            }
        }
        cin >> divs[i].size1 >> divs[i].size2;
    }
    
    // int query, division,all;
    // unsigned int k, k1, linhas;
    // string name_q;
    
    // for(int j=0;j<Q;j++){
    //     cin >> name_q >> query;
    //     if (query==1){
    //         for (k1 = 0; k1 < divs.size(); k1++) {
    //             if (divs.at(k1).name == name_q){
    //             division = divs.at(k1).size1;
    //             break;
    //             }
                
    //         }
                
    //             if (division==0){
    //                 vector <int> guardar;
                    
    //                 linhas=0;
    //                 while (division==0){
    //                     k=k1;
    //                     linhas=linhas+1;
    //                     guardar.push_back(k1);
    //                     for (k1 = 0; k1 < divs.size(); k1++) {
    //                         if (divs.at(k1).name == divs.at(k).mother->name){
    //                             division= divs.at(k1).size1;
    //                             break;
    //                         }
    //                     }
                        
    //                 }
    //                 k=k1;
    //                 for(k1=0;k1<guardar.size();k1++){
    //                     for(k2=0;k2<k.childs.size();k2++){
    //                         for (k4 = 0; k4 < divs.size(); k4++) {
    //                             if (divs.at(k4).name == divs.at(k4).mother->name){
    //                                 division= divs.at(k1).size1;
    //                             break;
    //                             }
    //                         }
                        
    //                         if (k1.childs[k2].name!=divs.at(guardar[k]).name && k1.childs[k2].size1==divs.at(guardar[k]).size1 ){
    //                             ver==0;
    //                             while(ver==0){
    //                                 for(k3=0;k3<k.childs.size();k3++){
                                        
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
                    
    //             }
    //                 else cout << division << division;
    //             }
    //             else
    //             for (k = 0; k < divs.size(); k++) {
    //                 if (divs.at(k).name == name_q){
    //             all = divs.at(k).size2;
    //             break;
    //             }
    //             if (all==0){
    //                 // qualquer coisa
    //                 linhas=0;
    //                 while (all==0 &&){
    //                     linhas=linhas+1;
    //                     for (k1 = 0; k1 < divs.size(); k1++) {
    //                         if (divs.at(k1).name == divs.at(k).mother){
    //                             division= divs.at(k1).size1;
    //                             break;
    //                         }
    //                     }
                        
    //                 }
    //             }
    //             else cout << all <<all;
                    
    //             }
                
    //         }
    //         }
    //     }
        
        
    // }
    
   int query, a;
string name_q;

for(int j=0;j<Q;j++){
    cin >> name_q >> query;
    divisionS * currentDiv;
    int lowerBound = 1, upperBound = 1;
    if (query == 1) {
    	for (unsigned k = 0; k < divs.size(); k++) {
    		if (divs[k].name == name_q) currentDiv = &divs[k];
    	}

    	if((a = (*currentDiv).size1) != 0) {
    		 lowerBound = a;
    		 upperBound = a;
    	}
    	else {
    		if ((*currentDiv).mother != NULL) {
	    		divisionS * mother = (*currentDiv).mother;

	    		int secondLevelSize2 = -1;
	    		if (mother->size2 == 0 && mother->mother != NULL) {
		    		divisionS * mothermother = mother->mother;
		    		int abc = mothermother->size1;
	    			if (abc == 0) abc = 1;
	    			int childTotal2 = mothermother->size2 - abc;
		    		int employeesInChild2 = 0;
		    		for (unsigned t = 0; t < mothermother->childs.size(); t++){
		    			if (mothermother->childs[t]->name != (*mother).name) {
		    				employeesInChild2 += mothermother->childs[t]->size2;
		    			}
		    		}
		    		secondLevelSize2 = childTotal2 - employeesInChild2;
	    		}

	    		int childTotal;
	    		if (secondLevelSize2 != -1) childTotal = secondLevelSize2;
	    		else {
	    			int ab = mother->size1;
	    			if (ab == 0) ab = 1;
	    			childTotal = mother->size2 - ab;
	    		}
	    		int employeesInChild = 0;
	    		for (unsigned i = 0; i < mother->childs.size(); i++){
	    			if (mother->childs[i]->name != (*currentDiv).name) {
	    				employeesInChild += mother->childs[i]->size2;
	    			}
	    		}
	    		int ab = (*currentDiv).size1;
	    		if (ab == 0) ab = 1;
	    		upperBound = childTotal - employeesInChild - ab;
	    	} else {
	    		upperBound = (*currentDiv).size1;
	    	}
    	}
    } else if (query == 2) {
    	for (unsigned k = 0; k < divs.size(); k++) {
    		if (divs[k].name == name_q) currentDiv = &divs[k];
    	}

    	if((a = (*currentDiv).size1) != 0) {
    		 lowerBound = a;
    		 upperBound = a;
    	}
    	else {
    		if ((*currentDiv).mother != NULL) {
	    		divisionS * mother = (*currentDiv).mother;

	    		int secondLevelSize2 = -1;
	    		if (mother->size2 == 0 && mother->mother != NULL) {
		    		divisionS * mothermother = mother->mother;
		    		int abc = mothermother->size1;
	    			if (abc == 0) abc = 1;
	    			int childTotal2 = mothermother->size2 - abc;
		    		int employeesInChild2 = 0;
		    		for (unsigned t = 0; t < mothermother->childs.size(); t++){
		    			if (mothermother->childs[t]->name != (*mother).name) {
		    				employeesInChild2 += mothermother->childs[t]->size2;
		    			}
		    		}
		    		secondLevelSize2 = childTotal2 - employeesInChild2;
	    		}

	    		int childTotal;
	    		if (secondLevelSize2 != -1) childTotal = secondLevelSize2;
	    		else {
	    			int ab = mother->size1;
	    			if (ab == 0) ab = 1;
	    			childTotal = mother->size2 - ab;
	    		}
	    		int employeesInChild = 0;
	    		for (unsigned i = 0; i < mother->childs.size(); i++){
	    			if (mother->childs[i]->name != (*currentDiv).name) {
	    				employeesInChild += mother->childs[i]->size2;
	    			}
	    		}
	    		lowerBound = childTotal - employeesInChild;
	    		upperBound = childTotal - employeesInChild;
	    	} else {
	    		upperBound = (*currentDiv).size1;
	    	}
    	}
    }

    cout << lowerBound << " " << upperBound << endl;
}
    
    
    return 0;
}