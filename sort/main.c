//
//  main.c
//  sort
//
//  Created by mac on 16/6/16.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbling_sort(int arr[] ,int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void select_sort(int arr[] ,int count){
    for (int i = 0; i < count; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}

void insert_sort(int arr[] ,int count){
    int i,j;
    int temp = 0;
    for (i = 0; i < count; i++) {
        temp = arr[i];
        for (j = i; j > 0 && temp > arr[j - 1];j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void precDown(int arr[] ,int number ,int count) {
    int parent ,child;
    int temp = arr[number];
    for (parent = number; (parent * 2 + 1) < count; parent = child) {
        child = parent * 2 + 1;
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

void heap_sort(int arr[] ,int count){
    for (int i = count / 2 - 1; i >= 0;i--) {
        precDown(arr, i, count);
    }
    for (int i = count - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        precDown(arr, 0, i);
    }
}

void shell_sort(int arr[] ,int count) {
    int i,j;
    int temp = 0;
    for ( int n = count / 2; n > 0; n = n / 2) {
        for (i = n;i < count; i++) {
            temp = arr[i];
            for (j = i; j >= n && temp > arr[j - n]; j-= n) {
                arr[j] = arr[j - n];
            }
            arr[j] = temp;
        }
    }
}

void quick_realize_sort(int arr[] ,int start ,int end){
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end - 1;
    int temp = arr[end];
    while (left < right) {
        while (left < right && temp > arr[left]) {
            left++;
        }
        while (left < right && temp <= arr[right]) {
            right--;
        }
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] < temp) {
        left++;
    }else {
        swap(&arr[left], &arr[end]);
    }
    quick_realize_sort(arr, start, left - 1);
    quick_realize_sort(arr, left + 1, end);
}

void quick_sort(int arr[] ,int count) {
    quick_realize_sort(arr ,0 ,count - 1);
}

void merge_sort_recursive_realize(int arr[] ,int temp[] ,int start ,int end){
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    
    merge_sort_recursive_realize(arr, temp, start1, end1);
    merge_sort_recursive_realize(arr, temp, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2) {
        temp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }
    while (start1 <= end1) {
        temp[k++] = arr[start1++];
    }
    while (start2 <= end2) {
        temp[k++] = arr[start2++];
    }
    for (k = start ; k <= end; k++) {
        arr[k] = temp[k];
    }
}

void merge_sort_recursive(int arr[] ,int count){
    int *temp = (int *)malloc(count * sizeof(int *));
    merge_sort_recursive_realize(arr, temp, 0, count - 1);
}

void merge_sort(int arr[] ,int count){
    int *temp = (int *)malloc(count * sizeof(int *));
    for (int i = 1; i < count; i+= i) {
        for (int j = 0;j < count; j += 2 * i) {
            int start = j;
            int mid = (start + i) < count ? (start + i) : count;
            int end = (start + i + i) < count ? (start + i + i) : count;
            int start1 = start ,end1 = mid;
            int start2 = mid, end2 = end;
            int k = start;
            while (start1 < end1 && start2 < end2) {
                temp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
            }
            while (start1 < end1) {
                temp[k++] = arr[start1++];
            }
            while (start2 < end2) {
                temp[k++] = arr[start2++];
            }
        }
        int *tempoary = arr;
        arr = temp;
        temp = tempoary;
    }
    free(temp);
}

void printArray(int arr[] ,int count){
    for (int i = 0; i < count; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = arc4random() % 100 + 1;
    }
    printArray(arr ,10);
    //    bubbling_sort(arr, 10);
    //    select_sort(arr, 10);
    //    insert_sort(arr, 10);
    //    heap_sort(arr ,10);
    //    shell_sort(arr ,10);
    //    quick_sort(arr, 10);
    merge_sort(arr, 10);
    printArray(arr ,10);
    return 0;
}
