//Shahriar Arefin
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#ifndef __RESOLUTION_PROVING_H___
#define __RESOLUTION_PROVING_H___

//using set to gurantee lietrals are in specific order ofr later implementation
typedef set<int> literal_set;

class Resolution_Prover 
{
    public:
        Resolution_Prover();
        ~Resolution_Prover();
        //Resolution Prover
        bool resolution_prover();
        void display_clauses();
        void load_CNF_file(char* file_path);

    private:
        map<string, literal_set> clauses_;
        int total_clauses;
        int total_variables;

        map<string, literal_set> apply_resolution_rule(const literal_set& ci, const literal_set& cj);
        literal_set tokens_to_clause(const vector<string>& tokens);
        string convert_clause_to_string(const literal_set& clause);

        //split strings by the delimiter into a vector of substrings.
        vector<string> split_clause(const string& sentence, char delimiter);
};

#endif