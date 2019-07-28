#include "evaluate.h"

// Creator Name: Stefan Vercillo
// The parameters that are taken into the function is firstly the file name of the expression 
// which is passed into argv[]. This main function takes the fileName and opens it, then reads and interprets its values. The second parameter passed is through the system input, which is the test file passing values into cin or the system. These values are used to process the truth value. The output or return type is a series of strings which state whether each test case is true or false for the given expression
int main(int, char* argv[]) {

	ifstream dimacs;
	int numVars;
	int numClauses;
	string thisChar;
	string fileName = argv[1];


	dimacs.open(fileName);
	if (!dimacs){
		cout << "Unable to open file";
	}

        dimacs >> numVars >> numClauses;

	vector <int> vecArr [numClauses]; 
	vector<int> varsVec;
	int count =0;
        while (dimacs>> thisChar){
                if (thisChar == "0"){
			vecArr[count] = varsVec;
			count++;
			varsVec.clear();
		} else {
			int thisInt = atoi(thisChar.c_str());
			varsVec.push_back(thisInt);
		}

    	}

	dimacs.close();
	
	vector<string> testStrVec;
	int numTest =0;
	while (cin >> thisChar) {
		if (thisChar == "0")
			numTest++;
		testStrVec.push_back(thisChar);
	}
	
	vector <int> testArr [numTest];
	vector <int> testVars;
	int countT =0;
	for (string thisChar : testStrVec){
		if (thisChar =="0"){
			testArr[countT] = testVars;
			countT++; 
			testVars.clear();
		} else {
			int thisInt = atoi(thisChar.c_str());
			if (thisInt< 0){
				thisInt = abs(thisInt);
				testVars.push_back(thisInt);
			}
		}
	}

	
	int c =0;
	for (vector<int> test: testArr){
		c++;
		int isStatementTrue =1;
		for (vector <int> clause : vecArr){
			int isClauseTrue =0;
			for (int var : clause){
				if (var >0 && (find(test.begin(), test.end(), var) == test.end()))
					isClauseTrue =1;
			else if (var <0 && (find(test.begin(), test.end(), var) != test.end()))
						isClauseTrue =1;
			}
			if (isClauseTrue == 0) 
				isStatementTrue =0;
		}
		if (isStatementTrue == 0)
			cout << "Test case " << c << " is false" << endl;
		else 
			cout <<"Test case " << c<<  " is true" << endl;
	}
		
	return 0;
}
