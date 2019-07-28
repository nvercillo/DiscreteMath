#include "Mean.h"

int main (int, char*argv[]){
        int random, stacksize;
          /* initialize random seed: */
//        srand (time(NULL));

        vector <int> stack;
        stacksize = 500;
        int count =-1;
        while (count< stacksize){
/* generate secret number between 1 and 10:
* change this to 0 to 110    % 111 */
                random = rand() % 11;
                if (random ==9 || random == 18){
                        if(count !=0) {
                                int old = stack[count];
                                stacksize = stacksize + old;
                        }

                } else if (random == 13) {
                        if (count !=0){
                                int old = stack[count];
                                // minus 1?
                // what if the subtracted number goes to zero?

                                if (count - old < 0){
                                        for (int i=0; i<= count; i++){
                                                stack.pop_back();
                                        }
                                        count = 0;
                                } else {
                                        for (int i= count; i>= count - old; i--){
                                                stack.pop_back();
                                        }
                                        count = count - old;
                                }
                        }
                } else {
                        count++;
                        stack.push_back(random);
                }
        }

//      for (int i :stack)
//              cout <<i <<endl;

        int sum=0;
        for (int j : stack){
                sum = sum + j;
        }
//      cout<< sum << endl;

cout << "MY stack size is "  << stacksize <<endl;
cout << "My sum  is " << sum << endl;
        float  mean = (float )sum / (float) stacksize;
        cout << "mean is " << mean

//      cout<< "Mean is:   " << mean << endl;
//      cout << stack.size()
        return 0;
}
                       
