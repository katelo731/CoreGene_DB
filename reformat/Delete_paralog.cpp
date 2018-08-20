#include "bits/stdc++.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main(){
	
    double START,END;
    START = clock();	// clock start
	
    ifstream in("5mul5resultDBm8");
    string inputStr;
    vector<string> inputContent;
    char id[6]={};	// id[6]= {id1[0],..,id1[2],id2[0],..,id2[2]}
    
    while(getline(in, inputStr)){
    	
    int c=0;
    int flag=0;
    	
    for(int i=0;i<inputStr.size();i++)
    {
        if(c>=6) break;
        if(isalpha(inputStr[i]))
        {
            id[c]=inputStr[i];
            c++;
        }
    }
    	
    for(int i=0;i<3;i++)
        if(id[i]!=id[i+3]) 
        {
            flag=1;
            break;
        }
		
    if(flag==1)
        inputContent.push_back(inputStr);
    }
    in.close();

    ofstream out("resultDBm8.out");
    for(int i=0; i < inputContent.size(); i++)
        out << inputContent[i] << endl;
    out.close();
    
    END = clock();    // clock end

    cout << endl << "Execution time : " << (END - START) / CLOCKS_PER_SEC << " sec" << endl;

    return 0;
}
