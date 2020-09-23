//Shahriar Arefin

#include "optimized_WALKSAT.h"

int main(int argc, char* argv[]) 
{	
  char* file_path;
	if (argc > 1) 
	{
        file_path = argv[1] ;
  } 
  else 
  {
        cout << "No file name entered. Exiting...";
        return -1;
  }
  cout << "Faster Implementation of WalkSAT Solver using C++" << endl;
  cout << "Problem trying to solve: " << file_path << endl;

  load_CNF_file(file_path);

  auto start_time = chrono::high_resolution_clock::now();
  map<int, bool> result = walk_sat(0.5, 20000);
  auto end_time = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
  cout << "Walk-SAT took "<< duration.count() << " milliseconds to run." << endl;

  assert(verify_sat_model(result));
  //display_sat_model(result);
  
  return 0;
}