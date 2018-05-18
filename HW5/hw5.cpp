
/*
  @info Dynamic programming assignment for CS 477
  @author Pedram Safaei
  @file hw5.cpp
  @bug none that can be seen with the acceptable test cases that the programmer has tried.
  @version 1.2
  @date 04/16/2018

          ******Important*********
    Please compile using the below command

      g++ -Wall -std=c++11 hw5.cpp Drone_Alg.cpp

    I am initializing vectors which is not acceptable in
    older versions of c++ so I have to use c++ 11
        ******Important*********
*/

#include "Drone_Alg.cpp"

int main()
{
   /*
     Please make sure to add a 0 to the beginning of each test case so if
     xi = 1 0 0 2 you should initilize the vector starting with 0 so
     0 1 0 0 2 that is just how the program works, I could enter a 0
     automatically but since we care more about the algorithm I did not
     want to deal with shifting and stuff.
   */
   // f values go here
   std::vector<int> Function_Value {0,1,2,4,8};
   // xi values go here
   std::vector<int> Xi_Value {0,1,10,10,1};


   std::unordered_map<int, Drones>  MAP_VALUE; // hold optimal values

   // solve subproblems
   std::vector<std::vector<int>> m( Function_Value.size(), std::vector<int>(Function_Value.size(), 0));
   Solution_Recursive_Relation( MAP_VALUE, m, Function_Value, Xi_Value );

   // PART B
   // solution
   std::cout <<"=====================================================================" << std::endl;
   std::cout << "                     ########## Part B ##########" << std::endl;
   std::cout <<"=====================================================================" << std::endl << std::endl;
   std::cout << "########## Part B SOLUTION ##########" << std::endl << std::endl;
   std::cout << "Max number of drones taken out in  " << MAP_VALUE.size()-1 << " seconds is ";
   std::cout << MAP_VALUE[MAP_VALUE.size()-1].MAX << '.'<< std::endl;

   std::cout << "____________________________________________________________________" << std::endl << std::endl;
   // PART B
   // table
   std::cout << "########## Part B TABLE ##########" << std::endl<< std::endl;
   std::cout << " i : After How many seconds " << std::endl;
   std::cout << " j : How many seconds[of charge]" << std::endl;
   TABLE_PARTB(m, Function_Value.size());
   std::cout <<"=====================================================================" << std::endl;

   // PART C
   // print out table of values
   std::cout << "                     ########## Part C ##########" << std::endl;
   std::cout <<"=====================================================================" << std::endl << std::endl;
   std::cout << "########## Part C Print out table of Values ##########" << std::endl << std::endl;
   std::cout << "Table Reconstructed to show where each subproblem's solution came from: " << std::endl;
   std::cout << "we require to fire at i, as well as during value in braces of (i,j) [of course recursively]" << std::endl;
   TABLE_PARTC(m, Function_Value.size());
   std::cout <<"=====================================================================" << std::endl;

   // PART D
   // print laser times
   std::cout << "                     ########## Part D ##########" << std::endl;
   std::cout <<"=====================================================================" << std::endl << std::endl;
   std::cout << "########## Part D printout of the solution ########## " << std::endl << std::endl;
   std::cout << "To take down " << MAP_VALUE[MAP_VALUE.size()-1].MAX << " drones in " << MAP_VALUE.size()-1 << " seconds, we must fire at seconds: ";

   for( unsigned int i = 0; i < MAP_VALUE[MAP_VALUE.size()-1].TIME.size(); i++ )
   {
      std::cout << MAP_VALUE[MAP_VALUE.size()-1].TIME[i] << ' ';
   }
   std::cout << std::endl;
   std::cout <<"=====================================================================" << std::endl << std::endl;

   return 0;
}
