#include <stdio.h>
// Calculate minimum number of moves to arrange array
// in increasing order.
int movetoFront(int arr[], int n){
   //take count as all elements are correctly placed
   int count = n;
   // Traverse array from end
   for (int i=n-1; i >= 0; i--){
      // If current item is at its correct position,
         //decrement the count
      //range is 1 to n so every arr[i] should have value i+1
      //1 at 0 index, 2 at 1 index........
      if (arr[i] == count)
         count--;
   }
   return count;
}
int maisn(){
   int Arr[] = {5, 3, 4, 7, 2, 6, 1};
   int size = 7;
   printf("%s|%d","Minimum 'move-to-front' to sort array:", movetoFront(Arr, size));
   return 0;
}