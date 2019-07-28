#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <iterator> 
#include <algorithm> 
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
using namespace std; 

int main ( int argc, char *argv[] ){
    string in = argv[1];

    if (in.size() ==0 )
        cout<< "Invalid Input!!!!!!!!!" << endl;
    
    char input [in.size() +1];
    strcpy(input, in.c_str());
    
    
    
    
    bool isAddition =false;
    if (input[1] == '+') isAddition=true;
    
    int numofVars=1;
    vector<char> varVector;
    for (int i=0; i<in.size(); i++){
        if (i%2 ==1) numofVars ++; 
        if (isalpha(in[i])) varVector.push_back(in[i]);
        // cout << in[i] << endl;
    }
    
    // cout << varVector[0] << endl; 
    // cout << varVector[1] << endl; 
    // cout << varVector[2] << endl;
    char firstBinCharArr [numofVars+1];
    for (int i; i<varVector.size(); i++){
        firstBinCharArr[i] = varVector[i];
    }
    cout << "Number of Variables is:  " << numofVars << endl;
	cout << "Boolean Expression:  " << in << endl;
    
    for(int j=0; j<pow(2, numofVars); j++){
        int numb = j;
        int binaryArr [numofVars];
        char binCharArr [numofVars+1];
        
        int count=0; 
        for(int i=0; numb>0; i++){    
            binaryArr[i]=numb%2;    
            numb = numb/2;  
            count++;
        }    
        for (int i = count; i<numofVars; i++){
            binaryArr[i] =0;
        }   
        
        char lastplacement;  
        bool containsOne=false;   
        bool containsZero = false; 
        for (int i=0; i< numofVars; i++){
            if(binaryArr[i] ==1){
                binCharArr[i] = 'T';
                containsOne =true; 
            } else {
                binCharArr[i] = 'F';
                containsZero =true;
            }
        }
        
        // lastplacement determination 
        if (isAddition){
            if (containsOne){
                lastplacement = 'T';
            } else {
                lastplacement = 'F';
            }
            
        } else {
            if (!containsZero){
                lastplacement = 'T';
            } else {
                lastplacement ='F';
            }
        }
        binCharArr[numofVars] = lastplacement;
        
        for (int i=0; i< numofVars+1; i++){
            if (i != numofVars)
                cout << binCharArr[i];
            else {
                cout << binCharArr[i]<< endl;
            }
        }
    }
    return 0;
}



