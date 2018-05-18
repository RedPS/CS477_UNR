/**
  @file maxheapify.cpp
  @brief given an array we apply maxheapify
  @author Pedram Safaei
  @version 1.0
*/
#include <iostream>
#include <algorithm>

void maxheapify (int list[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if(list[i] > list [(i-1)/ 2]) // if larger than parent
    {
      int larger = i;

      while(list[larger] > list[(larger - 1 )/ 2]) //if parent is smaller swap
      {
          std::swap (list[larger], list[(larger-1)/2]); // swap parent and child
          larger = (larger - 1) / 2;                    // update larger

          std::cout << "swapping " << (char)list[larger] <<" with " << (char)list[(larger-1)/2] << std::endl;
      }
    }
  }
}

int main()
{
  //int list[] = { 10, 20, 15, 17, 9, 21};
  //int list[] = {'o'};
  int list[] = {'O', 'T', 'X', 'G', 'S', 'P', 'N', 'A', 'E', 'R', 'A', 'I', 'M'};
  int size = sizeof(list) / sizeof (list[0]);

  std::cout << "Our Array: " << std::endl;
  for (int i = 0; i < size; i++)
  {
    //std::cout << list[i] << " " ;
    //std::cout << "["<< (char)list[i] << "] " ;
    //std::cout << "["<< list[i] << "] " ;
    std::cout << " "<< (char)list[i] << " " ;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Applying maxheapify: " << std::endl;
  maxheapify (list, size);
  std::cout << std::endl;

  std::cout << "After maxheapify: " << std::endl;
  for (int i = 0; i < size; i++)
  {
    //std::cout << list[i] << " " ;
    //std::cout << "["<< (char)list[i] << "] " ;
    //std::cout << "["<< list[i] << "] " ;
    std::cout << " "<< (char)list[i] << " " ;
  }
  std::cout << std::endl;
  return 0;
}
