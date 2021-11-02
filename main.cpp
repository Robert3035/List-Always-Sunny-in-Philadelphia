#include <iostream>
#include "list.h"
#include <fstream>

using namespace std;

int main(){
    List beiju;
    ifstream fin;
    fin.open("input2");
    ofstream fout;
    fout.open("outfile");
    string testCase;
    while(fin >> testCase){
        for(int i = 0; i < testCase.size(); i++){
            if(testCase[i] == '['){
                beiju.begin();
            }
            else if(testCase[i] == ']'){
                beiju.end();
            }
            else{
                beiju.insert_after(testCase[i]);
            }
        }
        beiju.begin();
        while(beiju.get_iterator() != ']'){
            if(beiju.get_iterator() != '['){
                fout << beiju.get_iterator();
            }
            beiju.move_up();
        }
        beiju.clear();
        fout << endl;
    }
    fout.close();
    fin.close();
}