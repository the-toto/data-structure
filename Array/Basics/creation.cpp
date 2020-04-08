#include <iostream>                                     // arr is group of variable of same data type 
#include <cstdlib>                                      // where, its name represent address and and subscript value to go to location 
#include <time.h>
#define SIZE 10
using namespace std;
void print(int arr[]) {                                 //   printing arr
  for (int i = 0; i < SIZE; ++i)               
    cout << arr[i] << ' ';
  cout << '\n';
}
void find(int arr[]) {                                  // finding biggest and smallest in arr
  int small, big;
  small = big = arr[0];
  for (int i = 1; i < SIZE; i++) {
    if (arr[i] > big)
      big = arr[i];
    if (arr[i] < small)
      small = arr[i];
  }
  cout << big << ' ' << small << '\n';
}
bool linear_search(int arr[], int item, int &pos) {      // searching a element in array by O(n)
  for (int i = 0; i < SIZE; i++)
    if (item == arr[i]) {
    	pos = i + 1;
    	return 1;
    } 
  return 0;
}
void left_rotation(int arr[], int factor) {              // rotating arr left by some factor
  int box[factor];
  for (int i = 0; i < factor; i++)
    box[i] = arr[i];
  for (int i = 0; i < SIZE; i++)
    arr[i] = arr[i + factor];
  for (int i = 0; i < factor; i++)
    arr[SIZE - factor + i] = box[i];
} 
void right_rotation(int arr[], int factor) {             // rotating arr right by factor 
  int box[factor];
  for (int i = 0; i < factor; i++)
    box[i] = arr[SIZE - factor + i];
  for (int i = SIZE - 1; i >= factor; i--)
    arr[i] = arr[i - factor];
 	for (int i = 0; i < factor; i++)
    arr[i] = box[i]; 
}                  	
int main() {                                             //  main function
  int arr[SIZE], pos;
  srand(time(0));     
  for (int i = 0; i < SIZE; ++i) {
    arr[i] = rand() % 100;
  }                
  print(arr);
  find(arr);
  int random = rand() % 100;
  if (linear_search(arr, random, pos))
    cout << random << " present at " << pos << '\n';
  left_rotation(arr, 2);  
  print(arr);
  right_rotation(arr, 3);
  print(arr);

return 0;
}  
