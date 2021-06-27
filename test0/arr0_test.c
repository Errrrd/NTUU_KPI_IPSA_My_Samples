#include <stdio.h>
#include <string.h>

void shakerSort(int arr[], int size) {
	int buff;
    int ctrl = size - 1;
	int left = 0;
	int right = ctrl;
    
    printf("[left:right]= [%d:%d], ", left, right);
	
    while (left < right ) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                buff = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buff;
                ctrl=i;
            }
        }
        right=ctrl;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                buff = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = buff;
                ctrl=i;
            }
        }
        left=ctrl;
        printf("[%d:%d], ", left, right);
	}
    printf("\n");
}

int main()
{
   int arr[10] = {5,6,7,8,9,10,11,12,13,14};
   for (int i=0; i < 9; i++)
       printf("%4d", arr[i]);
   printf("%4d\n\n", arr[9]);
   
   printf("sizeof(arr) = %4lu\n", sizeof(arr));
   
   memset(arr, 0, sizeof(arr));
   
   for (int i=0; i < 9; i++)
       printf("%4d", arr[i]);
   printf("%4d\n\n", arr[9]);
   
   
   int arr1[11] = {12,8,3,10,6,1,7,9,15,4,2};
   for (int i=0; i < 11; i++)
       printf("%4d", arr1[i]);
   printf("\n");
   
   shakerSort(arr1, 11);
   
   for (int i=0; i < 11; i++)
       printf("%4d", arr1[i]);
   printf("\n\n");
   
   int arr2[12] = {12,8,3,1,6,0,10,7,9,15,4,2};
   for (int i=0; i < 12; i++)
       printf("%4d", arr2[i]);
   printf("\n");
   
   shakerSort(arr2, 12);
   
   for (int i=0; i < 12; i++)
       printf("%4d", arr2[i]);
   printf("\n\n");
   
   int arr3[13] = {13, 12,11,10,9,8,7,6,5,4,3,2,1};
   for (int i=0; i < 13; i++)
       printf("%4d", arr3[i]);
   printf("\n");
   
   shakerSort(arr3, 13);
   
   for (int i=0; i < 13; i++)
       printf("%4d", arr3[i]);
   printf("\n\n");
   
   int arr4[13] = {1,2,3,4,5,6,7,8,9,10,11,12, 13};
   for (int i=0; i < 13; i++)
       printf("%4d", arr4[i]);
   printf("\n");
   
   shakerSort(arr4, 13);
   
   for (int i=0; i < 13; i++)
       printf("%4d", arr4[i]);
   printf("\n\n");
   
   return 0;
}