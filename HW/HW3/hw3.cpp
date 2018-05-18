
/**
  @file : hw3.cpp
  @brief: Question # 1
  This program will find the peak entry given a unimodal array
  Please note that the author has hardcoded the array in this program.
  @author: Pedram Safaei
  @version: 1.1
  @bug: None, works as intended
*/

/*
  if there is a key,
  we will be using a binary search tree

  index binsearch(number n, index low, index high,
          const keytype S[], keytype x)
      if low ≤ high then
          mid = (low + high) / 2
          if x = S[mid] then
              return mid
          elsif x < s[mid] then
              return binsearch(n, low, mid-1, S, x)
          else
              return binsearch(n, mid+1, high, S, x)
      else
          return 0
  end binsearch

Divide: search lower or upper half
Divide: select lower or upper half
Conquer: search selected half
Combine: None
Performance:
T(n)=T(n/2)+Θ(1)

After proving the recurrence will we get
T(n)=Θ(lgn)


Note to self: add the proof.
*/


#include <iostream>

int Peak(int Given_Array[], int lowest, int highest, int size)
{
  //int middle_value = lowest + ((highest - lowest)/2);
    int middle_value = (lowest + highest) / 2;
  if(
      (
        (middle_value == 0)||
        (Given_Array[middle_value-1]) <= Given_Array[middle_value]
      )
      &&
      (
        (middle_value == size - 1) ||
        (Given_Array[middle_value+1]) <= Given_Array[middle_value]
      )
    )
    return middle_value;

    if
    (
      (middle_value > 0)
      &&
      (Given_Array[middle_value - 1] > Given_Array[middle_value])
    )
    return Peak(Given_Array, lowest, (middle_value - 1), size);

    else
      return Peak(Given_Array, (middle_value+1), highest, size);
}

int main()
{
    int array [] = {1, 3, 4, 5, 6, 7, 8, 5, 2, 1};
    //int array[] = {5};
    int size = sizeof(array)/sizeof(array[0]);

    std::cout << "size of the array is:" << size << std::endl;

    int index = Peak(array, 0, size-1, size);

    std::cout << "The index for peak is "
              << index
              << std::endl;

    int value = array[index];

    std::cout << "The value at "
              << index
              << " "
              << "is: "
              << value
              << std::endl;

    return 0;
}
