//
//  main.c
//  sort
//
//  Created by mac on 16/6/16.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int count){
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubbling_sort(int arr[], int count){
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void select_sort(int arr[], int count){
    for (int i = 0; i < count; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            }
        }
    }
}

void insert_sort(int arr[], int count){
    int i, j;
    int temp = 0;
    for (i = 0; i < count; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] < temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void shell_sort(int arr[], int count){
    int i, j;
    int temp = 0;
    printf("%d ", count >> 1);
    for (int n = count >> 1; n > 0; n >>= 1) {
        printf("%d ",n);
        for (i = n; i < count; i++) {
            temp = arr[i];
            for (j = i; j >= n && arr[j - n] > temp; j -= n) {
                arr[j] = arr[j - n];
            }
            arr[j] = temp;
        }
    }
}

void precDown(int arr[], int number, int count){
    int parent, child;
    int temp = arr[number];
    for (parent = number; parent * 2 + 1 < count; parent = child) {
        child = parent * 2 + 1;
        if (child != count - 1 && arr[child] > arr[child + 1]) {
            child++;
        }
        if (arr[child] < temp) {
            swap(&arr[child], &arr[parent]);
        }else{
            break;
        }
    }
    arr[parent] = temp;
}

void heap_sort(int arr[], int count){
    for (int i = count / 2 - 1; i >= 0; i--) {
        precDown(arr, i, count);
    }
    for (int i = count - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        precDown(arr, 0, i);
    }
}

void merge_sort(int arr[], int count){
    int *temp = (int *)malloc(sizeof(int) * count);
    for (int i = 1; i < count; i += i) {
        for (int j = 0; j < count ; j += 2 * i) {
            int start = j;
            int mid = start + i < count ? start + i : count;
            int end = start + i + i < count ? start + i + i : count;
            
            int start1 = start;
            int end1 = mid;
            int start2 = mid;
            int end2 = end;
            
            int k = start;
            
            while (start1 < end1 && start2 < end2) {
                temp[k++] = arr[start1] > arr[start2] ? arr[start1++] : arr[start2++];
            }
            while (start1 < end1) {
                temp[k++] = arr[start1++];
            }
            while (start2 < end2) {
                temp[k++] = arr[start2++];
            }
        }
        int *tempoary = temp;
        temp = arr;
        arr = tempoary;
    }
}

void quick_recursive_sort(int arr[], int start, int end){
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end;
    int temp = arr[start];
    while (left < right) {
        while (left < right && arr[right] < temp) {
            right--;
        }
        if (left < right) {
            arr[left++] = arr[right];
        }
        while (left < right && arr[left] > temp) {
            left++;
        }
        if (left < right) {
            arr[right--] = arr[left];
        }
    }
    arr[left] = temp;
    quick_recursive_sort(arr, start, left - 1);
    quick_recursive_sort(arr, left + 1, end);
}

typedef struct{
    int start;
    int end;
}Range;

Range create(int start, int end){
    Range r;
    r.start = start;
    r.end = end;
    return r;
}

void quick_sort(int arr[], int count){
    if (count <= 0) {
        return;
    }
    Range r[count];
    int i = 0;
    r[i++] = create(0, count - 1);
    while (i) {
        Range range = r[--i];
        if (range.start > range.end) {
            continue;
        }
        int temp = arr[range.start];
        int left = range.start;
        int right = range.end;
        while (left < right) {
            while (left < right && arr[right] > temp) {
                right--;
            }
            if (left < right) {
                arr[left++] = arr[right];
            }
            while (left < right && arr[left] < temp) {
                left++;
            }
            if (left < right) {
                arr[right--] = arr[left];
            }
        }
        arr[left] = temp;
        r[i++] = create(range.start, left - 1);
        r[i++] = create(left + 1, range.end);
    }
    free(r);
}

int main(int argc, const char * argv[]) {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = arc4random() % 100 + 1;
    }
    print_array(arr, 10);
    //    bubbling_sort(arr, 10);
    //    select_sort(arr, 10);
    //    insert_sort(arr, 10);
    //    shell_sort(arr, 10);
    //    heap_sort(arr, 10);
    //    merge_sort(arr, 10);
    //    quick_recursive_sort(arr, 0, 9);
    quick_sort(arr, 10);
    print_array(arr, 10);
    return 0;
}
