//Shahriar Arefin
#include "resolution_proving.h"

//global variables

Resolution_Prover::Resolution_Prover() {}

Resolution_Prover::~Resolution_Prover() {}


bool Resolution_Prover::resolution_prover() 
{
  cout << "Resolution_prover_function_running" << endl;
  int last_clause_size = 0;
  string clause_start = "C";

  map<string, literal_set> new_clause;
  map<string, literal_set> resolvent;
  int i = 0;
  while (true) 
  { 
    
    last_clause_size = new_clause.size();
    // for (auto i = clauses_.begin(); i!=clauses_.end(); ++i)
    // { 
    //   cout << i->first << endl;
    // }
    for (auto iterator_i = this->clauses_.begin(); iterator_i!=this->clauses_.end(); ++iterator_i)
    { 
      //cout << "iterator_i->first: " << iterator_i->first << endl;
      for (auto iterator_j = iterator_i; iterator_j!=this->clauses_.end(); ++iterator_j) 
      {
        
        //cout << "iterator_j->first: " << iterator_j->first << endl << endl;
        //resolution rule is applied to them to remove the literal and its complement
        resolvent = apply_resolution_rule(iterator_i->second, iterator_j->second);
        
        // if no new clause can be added
        if (resolvent.count(clause_start) > 0)
        {
          cout << "Resolution_prover_function_done" << endl;
          return false;
        } 
        new_clause.insert(resolvent.begin(), resolvent.end());
      }
    }
    //two clauses resolve to yield the empty clause
    if (new_clause.size() == last_clause_size)
    {
      cout << "Resolution_prover_function_done" << endl;
      return true;
    }
    this->clauses_.insert(new_clause.begin(), new_clause.end());

  }


  // return false;
}

map<string, literal_set> Resolution_Prover::apply_resolution_rule(const literal_set& x, const literal_set& y) {
  
  map<string, literal_set> Result;
  literal_set temp_x;
  literal_set temp_y;
  for (auto iterator_x = x.begin(); iterator_x!=x.end(); ++iterator_x) 
  {
    for (auto iterator_y = y.begin(); iterator_y!=y.end(); ++iterator_y) 
    {

      if (((*iterator_x) * -1) == *iterator_y) 
      {
        //Create a temp and remove literals removed through resolution
        temp_x = x;
        temp_y = y;
        temp_x.erase(*iterator_x);
        temp_y.erase(*iterator_y);

        //Insert the newly clause into Result list
        temp_y.insert(temp_x.begin(), temp_x.end());
        Result.insert(make_pair(convert_clause_to_string(temp_y), temp_y));
      }
    }
  }
  return Result;
}

void Resolution_Prover::display_clauses() 
{
  cout << "display_clause_function_running" << endl;
  for(auto iterator = clauses_.begin(); iterator != clauses_.end(); ++iterator)
  {
    cout << iterator->first << endl;
  }
}


void Resolution_Prover::load_CNF_file(char* file_path) {
  string line;
  string END_OF_LINE = "0";
  char DELIMITER = ' ';

  ifstream input_file (file_path);
  if (input_file.is_open()) 
  {
    getline(input_file, line); 
    getline(input_file, line);
    vector<string> tokens = split_clause(line, DELIMITER);

    this->total_variables = stoi (tokens[2]);
    this->total_clauses = stoi (tokens[3]);

    int len = 0;
    for (int i = 0; i < total_clauses; i++) 
    {
      getline(input_file, line);
      vector<string> tokens = split_clause(line, DELIMITER);

      // Remove END_OF_LINE token
      len = tokens.size();
      assert(tokens[len-1] == END_OF_LINE);
      tokens.pop_back();

      literal_set clause = tokens_to_clause(tokens);
      pair<string, literal_set> clause_pair;

      for (int j = 0; j < len-1; j++) 
      {
        clause_pair = make_pair(convert_clause_to_string(clause), clause);
        this->clauses_.insert(clause_pair);
      }
    }
    cout << "File loading successful" << endl;
    input_file.close();
  }
  else
  {
    cout << "Unable to open file, check filename is correct" << endl;
  }
}


literal_set Resolution_Prover::tokens_to_clause(const vector<string>& tokens) 
{
  literal_set clause;
  for (int i = 0; i < tokens.size(); i++) 
  {
    clause.insert(stoi(tokens[i]));
  }
  return clause;
}

string Resolution_Prover::convert_clause_to_string(const literal_set& clause) 
{
  string encoding = "C";
  for (set<int>::iterator i = clause.begin(); i!=clause.end(); ++i) 
  {
    encoding = encoding + " " + to_string(*i);
  }
  return encoding;
}

vector<string> Resolution_Prover::split_clause(const string& string_, char delimiter) 
{

  vector<string> tokens;

  int start = 0;
  int word_length = 0;
  bool inword_ = false;

  for (int i = 0; i < string_.length(); i++) 
  {
    if (string_[i] == delimiter) {
      if (inword_ == true) 
      {
        string token = string_.substr(start, word_length);
        tokens.push_back(token);
      }
      start = i+1;
      word_length = 0;
      inword_ = false;
    }
    else 
    {
      word_length++;
      inword_ = true;
    }
  }
  if (inword_ == true)
  {
    tokens.push_back(string_.substr(start, word_length));
  }

  return tokens;
}

