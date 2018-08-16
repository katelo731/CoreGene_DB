#include "bits/stdc++.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    ifstream in("IDevalue");
    ofstream out("IDevalue_permu.out");
    string inputStr1, inputStr2;
    int evalue;
    
    while(in >> inputStr1 >> inputStr2 >> evalue){
    	if(inputStr1[0]>inputStr2[0] || ((inputStr1[0]==inputStr2[0]) && (inputStr1[1]>inputStr2[1])) || ((inputStr1[0]==inputStr2[0]) && (inputStr1[1]==inputStr2[1]) && (inputStr1[2]>inputStr2[2])))
    		out << inputStr2 << '\t' << inputStr1 << '\t' << evalue << endl;
    	else
    		out << inputStr1 << '\t' << inputStr2 << '\t' << evalue << endl;
    }
    in.close();
    out.close();
    return 0;
}
