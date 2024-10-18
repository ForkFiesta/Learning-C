#include<stdio.h>

int removeElement(int* nums, int numsSize, int val){

    int leftIdx = 0;
    int rightIdx = 0;

    for(rightIdx=0;rightIdx<numsSize;rightIdx++){

        if(nums[rightIdx]!= val){
            nums[leftIdx] = nums[rightIdx];
            leftIdx++;

        }
        
    }

    return leftIdx;

}


int main(){


    int nums[]= {0,1,2,2,3,0,4,2};
    int numsSize = 8;
    int val = 2;

    int k = removeElement(nums, numsSize, val);

    for (int i = 0; i<numsSize; i++){
        printf("%d, ", nums[i]);
    }
    printf("\n%d\n",k);
}