//filename: bitCounter.cpp
//jtsmq - Julia Shea- lab4 - 9/25

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//returns the number of 1's in the binary representation of x
int bitCounter(int x){
  if (x==0){ //base case 1
    return 0;
  }

  else if(x==1){ //base case 2
    return 1;
  }

  else if(x%2==1){ //if x is odd
    return bitCounter(floor(x/2)) + 1;
  }
  else{ //if x is even
    return bitCounter(x/2);
  }

}


int main(int argc, char *argv[]){
  int integerRep;

  //one parameter must be provided in addition to the executable
  if (argc!=2){
    cout<< "Please provide a valid input."<< endl;
  }

  
  else{
    for (int i = 1; i < argc; i++ ) {
      integerRep = atoi(argv[i]);
  }
    cout<<bitCounter(integerRep)<< endl;
  }
  
  return 0;
}
