#include <iostream>

// Problem: Complete the function that use pass-by-reference to fin the maximum in a sequence of number

// Breakdown: 
// 1st: Complete the function
// 2nd: Use the function in a sequence of numbers

// Pseudo-code:
// 1. Create function void findMax(int* max, int a)
// 2.   if a> *max then *max = a
// 3. In main function:
// 4.   Set n as the size of the array by user input
// 5.   Set i = 0
// 6.   If i<n then
// 7.       print "Enter elements"
// 8.       array[i] = input
// 9.       increment i
// 10.      go to step 6
// 11.   Set max as the first element in the arry
// 12.   If i<n
// 13.       Call the function findMax   
// 14.           first parameter is &max
// 15.           second parameter is array[i] 
// 16.       increment i
// 17.       go to 12
// 18.   Print the value of max
// 19.   End
// Complexity: O(n)

using namespace std;
void findMax(int &max, int a){
  if (a> max)
    max = a;
}

int main(){
  int n, i, elem;
  cout << "Enter the size of array: " << endl;
  cin >> n;
  int arr[n];
  for(i =0; i <n;i++){
    printf("\nEnter elemets: ");
    cin >> arr[i];
  }
  int max = arr[0];
  for ( i = 0; i < n; i++)
    findMax(max, arr[i]);
  printf("The maximum is: %d",max);
}