#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

long long int pt1,pt2;
string seq1,seq2;
int weight;
int f1=0,f2=0;

void find()
{
	ifstream ID("finalresult_ID");
	long long int IDnum;
	string ptseq;
	f1=0,f2=0;
	
	while(ID >> IDnum >> ptseq){
		if(f1==1 && f2==1) break;
		if(ptseq.size()!=seq1.size() && ptseq.size()!=seq2.size()) continue;
		
		if(!ptseq.compare(seq1)) {
			pt1=IDnum;
			f1=1;
		}
		else if(!ptseq.compare(seq2)){
			pt2=IDnum;
			f2=1;
		}
	}	
}

int main()
{
	ifstream IDwet("finalresult");
	ofstream out("finalresult_intnode");
	
	while(IDwet >> seq1 >> seq2 >> weight){
		find();
		
		out << pt1 << "\t" << pt2 << "\t" << weight << endl;
	}
	return 0;
} 
