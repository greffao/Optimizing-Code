#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM (100000)
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)
#define LARGEST_CACHE_SZ (32 * MB)
static unsigned char dummy_buffer[LARGEST_CACHE_SZ];

void clean_cache(){
	unsigned long long i;
	for (i = 0; i < LARGEST_CACHE_SZ; i++)
		dummy_buffer[i] += 1;
}

void copy(int copy[], int original[]){ 
    for(int i=0 ; i < TAM ; i++) copy[i] = original[i];
}

void quicksort(int values[], int began, int end){
	int i, j, pivo, aux;
	i = began;
	j = end - 1;
	pivo = values[(began + end) / 2];
	while (i <= j){
		while (values[i] < pivo && i < end) i++;
		while (values[j] > pivo && j > began) j--;
		if (i <= j){
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if (j > began) quicksort(values, began, j + 1);
	if (i < end) quicksort(values, i, end);
}

void heapsort(int a[], int n){
	int i = n / 2, pai, filho, t;
	while (1){
		if (i > 0){
			i--;
			t = a[i];
		}
		else{
			n--;
			if (n <= 0)	return;
			t = a[n];
			a[n] = a[0];
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < n) {
			if ((filho + 1 < n) && (a[filho + 1] > a[filho])) filho++;
			if (a[filho] > t){
				a[pai] = a[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else break;
		}
		a[pai] = t;
	}
}

void merge(int array[], int left, int mid, int right){
	int i, j, k;
	int size_left = mid - left + 1;
	int size_right = right - mid;
	int Left[size_left], Right[size_right];

	for (i = 0; i < size_left; i++)	Left[i] = array[left + i];
	for (j = 0; j < size_right; j++) Right[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < size_left && j < size_right){
		if (Left[i] <= Right[j]){
			array[k] = Left[i];
			i++;
		}
		else{
			array[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < size_left){
		array[k] = Left[i];
		i++;
		k++;
	}

	while (j < size_right){
		array[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int left, int right){
	if (left < right){
		int mid = (left + right) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++)	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void bubbleSort(int* arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;

			} 
		}
	}
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
		   {
			int aux = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = aux;
		   }
    }
}

int main(int argc, char *argv[]){

	srand(time(NULL));

	int array[TAM], copyArray[TAM];

	for (int i=0; i < TAM; i++)	array[i] = rand() % TAM;

	// MERGE SORT
	// clean_cache();
	// copy(copyArray, array);
	// mergeSort(copyArray, 0, TAM-1);

	// HEAPSORT
	// clean_cache();
	// copy(copyArray, array);
	// heapsort(copyArray, TAM);
	
	// QuickSort
	// clean_cache();
	// copy(copyArray, array);
	// quicksort(copyArray, 0, TAM);
	
	// InsertionSort
	clean_cache();
	copy(copyArray, array);
	insertionSort(copyArray, TAM);

	//BubbleSort
	clean_cache();
	copy(copyArray, array);
	bubbleSort(copyArray, TAM);

	//SelectionSort
	clean_cache();
	copy(copyArray, array);
	selectionSort(copyArray, TAM);
	
	return 0;
}
