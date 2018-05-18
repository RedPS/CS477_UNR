/**
  @file : FindPeak.cpp
  @brief: Question # 1
  This program will find the peak entry given a unimodal array
  Please note that the author has hardcoded the array in this program.
  @author: Pedram Safaei
  @version: 1.1
  @bug: None, works as intended
*/

#include <iostream>

int findpeak (int array[], int low, int high)
{
  int middle = (low+high)/2; // find the middle value

  //if middle value is greater than the previous one
  // and less than the next one
  //pass the one after for low and continue
  if (array[middle] > array[middle-1] && array[middle] < array[middle+1])
  {
    return findpeak(array, middle+1, high);
  }

  //if middle value is less than the previous one
  // and greater than the next one
  //pass the one before for high and continue
  if (array[middle] < array[middle-1] && array[middle] > array[middle+1])
  {
    return findpeak(array, low, middle-1);
  }
  else
  {
    return middle;
  }
}
int main()
{
  int peakposition;
  int peakvalue;

  //As the instructions stated that the array will be increasing to a position,
  //I'll assume there will be more than 3 numbers or at least 3.
  int array[] = {1, 3, 4, 5, 6, 7, 8, 5, 2, 1};
  int size = sizeof(array)/sizeof(array[0]);

  peakposition = findpeak(array, 0, size);

  peakvalue = array[peakposition];

  std::cout << "The position of peak is: "
            << peakposition << std::endl;

  std::cout << "The value at that position is: "
            << peakvalue << std::endl;
  return 0;
}
