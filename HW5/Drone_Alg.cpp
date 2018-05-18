
/*
  @info Dynamic programming assignment for CS 477
  @author Pedram Safaei
  @file Drone_Alg.cpp
  @bug none that can be seen with the acceptable test cases that the programmer has tried.
  @version 1.2
  @date 04/16/2018
*/

/*
  including unordered map: since Unordered maps are associative containers
  that store elements formed by the combination of a key value and a mapped value,
  and which allows for fast retrieval of individual elements based on their keys.

  including iterator and algorithm to use the built in librarires so I don't have to
  implement anything more than the actual algorithm.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <algorithm>


// info about our drones
class Drones
{
public:
   int MAX = 0;
   std::vector<int> TIME;
   unsigned int PREVIOUS = 0;
};

// solve solution, recursive relation solution
void Solution_Recursive_Relation( std::unordered_map<int, Drones>  &MAP_VALUE, std::vector<std::vector<int>> &m, std::vector<int> &Function_Value, std::vector<int> Xi_Value )
{
   unsigned int i;
   unsigned int j;
   std::vector<int>::iterator maxPtr; // Im using STL just to save time

   // loop through
   for( i = 1; i < Function_Value.size(); i++ )
   {
      m[i][0] = 0;
      for(j = 1; j <= i; j++ )
      {
         m[i][j] = MAP_VALUE[i-j].MAX + std::min( Xi_Value[i], Function_Value[j] );
      }
      // find max for second
      maxPtr = max_element(m[i].begin(), m[i].end());
      j = distance(m[i].begin(), maxPtr );

      // save optimal
      MAP_VALUE[i];
      MAP_VALUE[i].MAX = *maxPtr;

      // part C
      MAP_VALUE[i].PREVIOUS = i - j;

      //part D
      MAP_VALUE[i].TIME = MAP_VALUE[i-j].TIME;
      MAP_VALUE[i].TIME.push_back(i);
   }

}

//print table part B
void TABLE_PARTB( std::vector<std::vector<int>> &m, unsigned int size )
{
   unsigned int i, j;

   std::cout << "          j: " << std::endl << "            ";

   for( unsigned int i = 1 ; i < size; i++ )
   {
      std::cout << i << ' ';
   }

   std::cout << "            " << std::endl << std::endl;

   //subproblems
   for( i = size - 1 ; i > 0; i-- )
   {
      if( i == (size/2) )
      {
         std::cout << "i:        ";
      }
      else
      {
         std::cout << "          ";
      }
      std::cout << i << "  ";
      for( j = 1; j <= i ; j++ )
      {
         std::cout << m[i][j] << ' ';
      }
      std::cout << std::endl;
   }
}

//print the reconstructed table part C
void TABLE_PARTC( std::vector<std::vector<int>> &m, unsigned int size )
{
   unsigned int i, j;

   std::cout << "            j: " << std::endl << "               ";
   for( unsigned int i = 1 ; i < size; i++ )
   {
      std::cout << i << "    ";
   }
  std::cout << std::endl << std::endl;
   // subproblems
   for( i = size - 1 ; i > 0; i-- )
   {
      if( i == size/2 )
      {
         std::cout << "i:        ";
      }
      else
      {
         std::cout << "          ";
      }
      std::cout << i <<"   ";
      for( j = 1; j <= i ; j++ )
      {
         std::cout << m[i][j]<< "{" << i-j << "}" << ' ';
      }
      std::cout << std::endl;
   }
}
