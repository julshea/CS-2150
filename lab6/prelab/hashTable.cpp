//Filename: hashTable.h
//Julia Shea - jts6mq - lab6 - 10/20/2019

#include "hashTable.h"
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//default constructor
hashTable::hashTable(int size){
  buckets = new vector<list<string>>;
  buckets->resize(size);
 
  numInserts = 0;
}

//destructor
hashTable:: ~hashTable(){
  delete buckets;
}

//assigns each string a hash value
//i've chosen to use this function for the prelab: the summation of characters in the string % vector size

unsigned int hashTable::hashFunction(const string &s) const{
  char *cstr = new char [s.length() + 1];
  strcpy(cstr, s.c_str());
  int count = 0;
  for(int i=0; i<(s.length() + 1); i++){
    count = count + cstr[i];
  }
  delete[] cstr;
  return (count % buckets->size());
  
}

//inserts a string into the hashtable using the hashFunction
void hashTable::insert(const string &s){
  buckets->at(hashFunction(s)).push_back(s);
  numInserts ++;
}

//returns true if a given string is in hashtable, false if it's not
bool hashTable::contains(const string &s){ 
  list<string> &l = buckets->at(hashFunction(s));
  return (find(l.begin(),l.end(),s) != (l.end()));
    
}


bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; 
}
