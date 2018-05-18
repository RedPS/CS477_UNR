#include <iostream>
#include <algorithm>


void maxheapify (int list[], int size)
{
  //start building the heap
  for(int i = 0; i < size; i++)
  {
    if(list[i] > list [(i-1)/ 2]) // if larger than parent
    {
      int larger = i;

      while(list[larger] > list[(larger - 1 )/ 2]) //if parent is smaller swap
      {
          std::swap (list[larger], list[(larger-1)/2]); // swap parent and child
          larger = (larger - 1) / 2;                    // update larger
      }
    }
  }
  // building heap finished

  // start maxheapify
/*
  for (int i = size - 1; i > 0; i--)
  {
    std::swap(list[0], list[i]);

    int index = 0;
    int larger = 0;

    do
    {
      index = (2*larger + 1);
      //left smaller than right, point to right
      if (list[index] < list[index + 1] && index < (i - 1))
      {
        index++;
      }
      //if parent smaller than child, swap
      if(list[larger] < list [index] && index < 1)
      {
        std::swap (list[larger], list[index]);
      }
      larger = index;

    } while(index < i);
  }
  */
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
    std::cout << (char)list[i] << " " ;
  }
  std::cout << std::endl;

  maxheapify (list, size);

  std::cout << "Applying maxheapify: " << std::endl;
  for (int i = 0; i < size; i++)
  {
    //std::cout << list[i] << " " ;
    std::cout << (char)list[i] << " " ;
  }
  std::cout << std::endl;
  return 0;
}
