#include "trust.h"



int main (int, char*argv[]){

	int numRels;
	int empty; 
	string thisChar;
	

	cin >> numRels; 
	 


	int adjMatrix [numRels][numRels];
	for (int j =0; j< numRels; j++){
		for (int i=0; i< numRels; i++) {
			if (i!= j)
				adjMatrix[i][j] = 0;  
		}
	}
       	
	

	

	// CREATE ADJACENCY MATRIX	
	int count =0;
	int count2 =0; 
	while (cin >> thisChar){
		if (thisChar == "0"){
			count++;
			count2 = 0;
		} else if (count2 != 0 ) {		
			int thisInt = atoi(thisChar.c_str()) -1;
			//cout << "This int is .. ." << thisInt<< endl;
			adjMatrix[thisInt][count] = 1;

		} else 
			count2++;
	}

	
//              TEST FOR ADJACNECY
//      for (int j=0; j <numRels; j++) {
//              for (int i=0; i< numRels; i++){
//                      if (i!= numRels-1){
//                              cout << adjMatrix[i][j];
//                      } else {
//                              cout << adjMatrix[i][j] << endl;
//                      }
//              }
//      }



	// ADD REFLEXIVITY
	for (int j=0; j< numRels; j++){
		for (int i=0; i< numRels; i++){
			if (i == j && adjMatrix[i][j] != 1)
				adjMatrix[i][j] = 1;	
		}
	}	
	

//		TEST FOR REFLEXIVITY
	for (int j=0; j <numRels; j++) {
		for (int i=0; i< numRels; i++){
			if (i!= numRels-1){
//				cout << adjMatrix[i][j]; 
			} else {
//				cout << adjMatrix[i][j] << endl; 
			}
		}
	}

	
	// ADD TRANSITIVITY 
	for (int k =0; k< numRels; k++){
		for (int i =0; i< numRels; i++){
			for (int j=0; j< numRels; j++) {						
				adjMatrix[i][j] = adjMatrix[i][j] || (adjMatrix[i][k] && adjMatrix[k][j]);
			}
		}	
	}
	


// 		TRANSITIVITY TEST
//        for (int j=0; j <numRels; j++) {
//                for (int i=0; i< numRels; i++){
//                        if (i!= numRels-1){
//                              cout << adjMatrix[i][j];
//                        } else {
//                                cout << adjMatrix[i][j] << endl;
//                        }
//                }
//        }



//	initializing the two dimensional data structure which contains a list (vector) of rows 
	vector <int> rowVec [numRels];
	for (int j=0; j<numRels; j ++ ){
		vector <int> row; 
		for (int i=0; i<numRels; i++) {
			row.push_back(adjMatrix[i][j]); 
		}
		rowVec[j] = row; 
	}
	
	// might not use all of the space in this array
	vector <int> outputVec [numRels];
	int j =-1;
	vector<int> universalChecker;
	for (vector<int> row1 : rowVec){
		j++;
		int i =-1; 
		vector <int> checkedIndex;
		for(vector<int> row2 : rowVec){
			i++; 
			bool rowsEqual = true; 
			for (int k=0; k< numRels; k++){
				if (row1 [k] != row2[k])
					rowsEqual = false;
			}
			
			if ( i>= j && rowsEqual && (find(checkedIndex.begin(), checkedIndex.end(), i+1)== checkedIndex.end())  &&  (find(universalChecker.begin(), universalChecker.end(), i+1) == universalChecker.end())){
				checkedIndex.push_back(i+1);
			}
		}
		for ( int d : checkedIndex){
			universalChecker.push_back(d); 
		}
		outputVec[j] = checkedIndex;

	}
	
	int c1=-1; 
	for (vector<int> row : outputVec){
		c1++; 
		if (row.size() == 0){}
		else if (row.size() ==1)
			cout <<"{" <<row[0] << "}" << endl; 
		else {
			cout << "{";
			int c2=-1;
			for (int i=0; i< row.size(); i++){
				if (i == row.size() -1)
					cout << row[i] << "}" << endl;  
				else 
					cout << row[i] << ",";
			}	
		}
	}
	

	return 0;

}	
