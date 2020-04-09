#include <iostream>
#include <cstdlib>
#include <time.h>
#define SIZE 100
using namespace std;

void print(int matrix[][SIZE], int size) {      //printing matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << matrix[i][j] << ' ';
     }
  	cout << '\n';
  }
}
int diagonal_sum(int matrix[][SIZE], int size) {          
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += matrix[i][i];
  return sum;
}
int diagonal2_sum(int matrix[][SIZE], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += matrix[i][size - i - 1];
  return sum;
}
int main() {
  int total = 0, matrix[SIZE][SIZE], n;
  n = 5;
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < n; j++) {
  		matrix[i][j] = rand() % 10;
  		total += matrix[i][j];
  	}
  } 
  print(matrix, n);
  cout << "the total is " << total << '\n';
  cout << diagonal_sum(matrix, n) << '\n';
  cout << diagonal2_sum(matrix, n) << '\n';  
  total = 0;
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < n; j++) {
      matrix[j][i] = 0;
      total += matrix[j][i];
  	}
  }
  print(matrix, n);
  cout << "the sum is " << total << '\n';
return 0;
}
