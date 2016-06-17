//
//  main.c
//  sort
//
//  Created by mac on 16/6/16.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int a[],int count){
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}


void insertSort (int arr[], int n)
{
    int i, j;
    int temp = 0;
    
    for(i = 0; i < n; i++)
    {
        temp = arr[i]; //取出一个元素
        //取出的元素和其前面的元素相比较
        for(j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            //如果前面的元素较大，则后移一位
            arr[j] = arr[j - 1];
        }
        //取出的元素填充到前面的元素空位
        arr[j] = temp;
    }
}



void shellSort(int arr[] ,int count) {
    int i, j;
    int temp = 0;
    for (int d = count / 2; d > 0; d = d / 2) {
        for(i = d; i < count; i++)
        {
            temp = arr[i]; //取出一个元素
            //取出的元素和其前面的元素相比较
            for(j = i; j >= d && temp < arr[j - d]; j -= d)
            {
                //如果前面的元素较大，则后移一位
                arr[j] = arr[j - d];
            }
            //取出的元素填充到前面的元素空位
            arr[j] = temp;
        }

    }
}

void percDown(int arr[] ,int number ,int count) {
    int parent ,child;
    int temp = arr[number];
    for (parent = number; (parent * 2 + 1) < count; parent = child) {
        child = parent * 2  + 1;
        if (child != count - 1 && arr[child] < arr[child + 1]) {
            child++;
        }
        if (temp >= arr[child]) {
            break;
        }else {
            arr[parent] = arr[child];
        }
    }
    arr[parent] = temp;
}

void heapSort(int arr[] ,int count) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        percDown(arr, i, count);
    }
    for (int i = count - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        percDown(arr, 0 ,i);
    }
}

void mergeSort(int arr1[] ,int arr2[] ,int count1 ,int count2 , int result[]) {
    int arrCount1 = 0,arrCount2 = 0;
    int count = 0;
    while (arrCount1 < count1 && arrCount2 < count2) {
        if (arr1[arrCount1] > arr2[arrCount2]) {
            result[count++] = arr2[arrCount2++];
        }else {
            result[count++] = arr1[arrCount1++];
        }
    }
    while (arrCount1 < count1) {
        result[count++] = arr1[arrCount1++];
    }
    while (arrCount2 < count2) {
        result[count++] = arr2[arrCount2++];
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[] ,int start ,int end) {
    if (start >= end) {
        return;
    }
    int temp = arr[end];
    int left = start ,right = end - 1;
    while (left < right) {
        while (arr[left] < temp && left < right) {
            left++;
        }
        while (arr[right] >= temp && left < right) {
            right--;
        }
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end]) {
        swap(&arr[left], &arr[end]);
    }else {
        left++;
    }
    
    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
}

void text(int arr[] ,int start ,int end){
    if (start >= end) {
        return;
    }
    int temp = arr[end];
    int left = start;
    int right = end - 1;
    while (left < right) {
        while (left < right && arr[left] < temp) {
            left++;
        }
        while (left < right && arr[right] >= temp) {
            right--;
        }
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end]) {
        swap(&arr[left], &arr[end]);
    }else {
        left++;
    }
    
    text(arr, start, left - 1);
    text(arr, left + 1, end);
}

void selectionSort(int arr[] ,int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int a[] ,int count) {
    printf("\n");
    for ( int i = 0 ; i < count; i++) {
        printf("%d ",a[i]);
    }
}

int main(int argc, const char * argv[]) {

    int a[10];
//    int arr1[5] = {1,3,5,7,15};
//    int arr2[6] = {2,6,8,10,20,30};
    for (int i = 0; i < 10; i++) {
        a[i] = arc4random() % 100 + 1;
    }
    printArray(a, 10);
//    bubbleSort(a, 10);
//    insertSort(a, 10);
//    shellSort(a, 10);
    
//    selectionSort(a, 10);
    heapSort(a ,10);
//    mergeSort(arr1, arr2, 5, 6, a);
//    quickSort(a, 0, 9);
//    text(a, 0, 9);
    printArray(a, 10);
    return 0;
}
