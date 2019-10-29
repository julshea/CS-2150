//filename: prelab4.cpp
//Julia Shea - jts6mq - lab4 - 9/22

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

//when called, prints out the size of the data type in bytes
void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes" << endl;
  cout << "Size of char: " << sizeof(char) << " bytes" << endl;
  cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
  cout << "Size of int*: " << sizeof(int*) << " bytes" << endl;
  cout << "Size of char*: " << sizeof(char*) << " bytes" << endl;
  cout << "Size of double*: " << sizeof(double*) << " bytes" << endl;
}

//takes in an unsigned int as an argument, and returns that int in 32-bit binary representation
void outputBinary(unsigned int x){
  int remainder;
  int binary [32]; //we know that we will always want a 32-bit array

  // cout << "Enter an integer value to be converted into binary: "<< endl;
  // cin >> x;

  //algorithm to convert the passed unsigned int to binary format
  for(int i=0; i<32; i++){
      remainder=x%2;
      x=x/2;
      binary[i]=remainder;
  }

  //reverse the array to format into big endian
  reverse(binary, binary+32);

  //print the array
  for(int i=0; i<32; i++){
    cout << binary[i];}
}

void overflow(){
  unsigned int x = 4294967295;
    x = x+1;
    cout << "\n4294967295+1 = " << x << endl;
    cout << "Adding 1 to the max value of an unsigned int results in a value of 0, because 0 is the minumum value for unsigned integers. Integer overlflow causes the compiler to retain only the least significant digits in the result and effectiely 'wrap' back around to the smallest number in the range.";
}



int main(){
  unsigned int y;

  sizeOfTest();
  cout << "Enter an integer value to be converted into binary: "<< endl;
  cin >> y;
  outputBinary(y);
  overflow();

  
  return 0;
}
