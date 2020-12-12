//#include "test_runner.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons)
{
   cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;;
   
   cout << "Median age for females = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::FEMALE; 
       })) << endl;

   cout << "Median age for males = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::MALE; 
       })) << endl;

   cout << "Median age for employed females = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::FEMALE && pers.is_employed == true;
       })) << endl;

   cout << "Median age for unemployed females = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::FEMALE && pers.is_employed == false;
       })) << endl;

   cout << "Median age for employed males = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::MALE && pers.is_employed == true;
       })) << endl;

   cout << "Median age for unemployed males = " << 
   ComputeMedianAge(persons.begin(), partition(persons.begin(), persons.end(),
       [](const Person& pers)
       {
           return pers.gender == Gender::MALE && pers.is_employed == false;
       })) << endl;
}
