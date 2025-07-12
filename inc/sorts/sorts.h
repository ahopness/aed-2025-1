#ifndef SORTS_H
#define SORTS_H

void bubble_sort(int arr[], int n); // O(n^2)
void insertion_sort(int arr[], int n); // O(n^2)
void merge_sort(int arr[], int left, int right); // O(n log n)
void quick_sort(int arr[], int low, int high); // O(n log n)
void heap_sort(int arr[], int n); // O(n log n)
void bogosort(int arr[], int n); // O(n!)

void initialize_random(); // Inicializa o gerador de números aleatórios

#endif