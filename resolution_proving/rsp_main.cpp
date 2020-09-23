//Shahriar Arefin
#include "resolution_proving.h"

int main(int argc, char* argv[]) 
{ 
  char* file_path;
  if (argc > 1) 
  {
        file_path = argv[1] ;
  } 
  else 
  {
        cout << "Error: No file name entered. USE: ./resolution (filename)";
        return 1;
  }

  cout << "Propositional theorem prover based on resolution using C++" << endl;
  cout << "Problem trying to solve: " << file_path << endl;

  Resolution_Prover* rsp = new Resolution_Prover();
  rsp->load_CNF_file(file_path);

  //https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
  auto start_time = chrono::high_resolution_clock::now();
  bool result = rsp->resolution_prover();
  auto end_time = chrono::high_resolution_clock::now();
  delete rsp;

  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
  cout << "resolution_prover took "<< duration.count() << " milliseconds to run." << endl;

  if (!result)
  {
    cout << "Answer: FALSE" << endl;
  }
  else
  {
    cout << "Answer: TRUE" << endl;
  }


  //cout << result << endl;
  //display_clauses();
  return 0;
}