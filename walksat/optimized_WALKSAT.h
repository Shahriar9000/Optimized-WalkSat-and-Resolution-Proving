//Shahriar Arefin

#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <chrono>

using namespace std;

#ifndef __WALKSAT_H__  //just to prevent double declaration of any identifiers such as types, enums and static variables
#define __WALKSAT_H__


map<int, bool> walk_sat(float p, int max_flips); //using map data structure for the key-value pair
void load_CNF_file(char* file_path);    
void display_sat_model(const map<int, bool>& model);    
bool verify_sat_model(const map<int, bool>& model);


//returns clauses not satisfied by the model for the problem
void check_assigned_model(const map<int, bool>& model, int changed_symbol);
//check if the model satisfies the disjointed  literals clause.
bool if_correct_clause(const vector<int>& clause, const map<int, bool>& model);
//counts the number of clauses statisfied by the model if we flip var's value.
int count_unsat_change(map<int, bool>& model, int var);
//check if a certain symbol exists in specific clause
bool if_symbol_exists(const vector<int>& clause, int symbol);

//helper functions
//split strings by the delimiter into a vector of substrings.
vector<string> split_clause(const string& sentence, char delimiter);
string convert_clause_to_string(const vector<int>& clause);


#endif
