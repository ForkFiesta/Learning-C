#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *return_array=malloc(sizeof(int)*2);

    for (int i = 0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j]==target){
                
                return_array[0]=i;
                return_array[1]=j;
                *returnSize = 2;
                return return_array;
            }
        }
    }

    *returnSize=0;
    return NULL;




    
}


int main(){

    int nums[] = {3,2,4};

    int numsSize=3;
    int target = 6;
    int returnSize;

    int* result=twoSum(nums, numsSize, target, &returnSize);

    printf("Result: ");
    printf("[");
    for(int i=0;i<returnSize;i++){
        printf("%d", result[i]);
    }
    printf("]");




}