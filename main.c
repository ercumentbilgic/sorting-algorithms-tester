#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <errno.h> 

#define MAX_INPUT_SIZE 10000000 // change the maximum input size right here.  default: 10000000
#define WARNING_THRESHOLD 1000000 // change the warning threshold right here. default: 1000000

void commandList(void);
void endOfAlgorithm(int temp[], int size); 

int inputSizeSetter(void);

void randomArrayGenerator(int array[], int size); 
void arrayCloner(int array[], int temp[], int size); 
void arrayPrinter(int array[], int size); 

void insertionSort(int temp[], int size); 
void selectionSort(int temp[], int size); 
void bubbleSort(int temp[], int size); 

void mergeSort(int temp[], int left, int right);
void merge(int temp[], int left, int k, int right); 

void quickSort(int temp[], int first, int last);

void swap(int *a, int *b);
void heapify(int temp[], int size, int i); 
void heapSort(int temp[], int size); 


int main(void)
{
    
    srand(time(NULL));

    while (1)
    {
        clock_t start, end;
        int *array = NULL; 
        int *temp = NULL;  
        char command[20];
        int inputSize;

        inputSize = inputSizeSetter();

        array = malloc(sizeof(int) * inputSize);
        if (array == NULL) {
            perror("Error allocating memory for 'array'");
            exit(EXIT_FAILURE); 
        }

        temp = malloc(sizeof(int) * inputSize);
        if (temp == NULL) {
            perror("Error allocating memory for 'temp'");
            free(array);
            exit(EXIT_FAILURE);
        }

        randomArrayGenerator(array, inputSize); 

        printf("Use 'cmd' to list all commands\n");

        while (1)
        {
            arrayCloner(array, temp, inputSize); 
            printf("main > ");
            scanf("%s", command);

            if (strcmp(command, "cmd") == 0)
            {
                commandList();
            }
            else if (strcmp(command, "1") == 0)
            {
                insertionSort(temp, inputSize); 
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "2") == 0)
            {
                selectionSort(temp, inputSize); 
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "3") == 0)
            {
                bubbleSort(temp, inputSize); 
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "4") == 0)
            {
                printf("main > Merge Sort > Loading...");
                fflush(stdout); 
                start = clock();
                mergeSort(temp, 0, inputSize - 1); 
                end = clock();
                printf("\n\n-> The running time of Merge Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, inputSize);
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "5") == 0)
            {
                printf("main > Quick Sort > Loading...");
                fflush(stdout); 
                start = clock();
                quickSort(temp, 0, inputSize - 1); 
                end = clock();
                printf("\n\n-> The running time of Quick Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, inputSize);
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "6") == 0)
            {
                printf("main > Heap Sort > Loading...");
                fflush(stdout); 
                start = clock();
                heapSort(temp, inputSize); 
                end = clock();
                printf("\n\n-> The running time of Heap Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, inputSize);
                endOfAlgorithm(temp, inputSize); 
            }
            else if (strcmp(command, "clear") == 0)
            {
                system("@cls||clear");
            }
            else if (strcmp(command, "input") == 0)
            {
                
                if (array != NULL) free(array);
                if (temp != NULL) free(temp);
                
                break; 
            }
            else if (strcmp(command, "print") == 0)
            {
                arrayPrinter(array, inputSize); 
            }
            else if (strcmp(command, "<") == 0)
            {
                
                if (array != NULL) free(array);
                if (temp != NULL) free(temp);
                exit(EXIT_SUCCESS);
            }
            else
            {
                printf("%s: command not found\n", command);
            }
        }
    }
    return 0;
}



void commandList(void)
{
    printf("[<]        -> exit program\n");
    printf("[cmd]      -> list all commands\n");
    printf("[clear]    -> clear terminal\n\n");

    printf("[input]    -> change the input size\n");
    printf("[print]    -> show randomly created (unsorted) array\n\n");

    printf("[1] -> run Insert Sort algorithm\n");
    printf("[2] -> run Selection Sort algorithm\n");
    printf("[3] -> run Bubble Sort algorithm\n");
    printf("[4] -> run Merge Sort algorithm\n");
    printf("[5] -> run Quick Sort algorithm\n");
    printf("[6] -> run Heap Sort algorithm\n\n");
}

int inputSizeSetter(void)
{
    int inputSize;
    do
    {
        printf("Please enter the input size: ");
        scanf("%d", &inputSize);

        if (inputSize <= 0)
        {
            printf("Input size can't be zero or negative number.\n");
        }
        else if (inputSize > MAX_INPUT_SIZE) 
        {
            printf("Input size can't be bigger than %d Million\n", MAX_INPUT_SIZE / 1000000);
        }
        else if (inputSize > WARNING_THRESHOLD && inputSize <= MAX_INPUT_SIZE) 
        {
            printf("\nWARNING! You entered a big input size. Processes may take long time\n");
            printf("To change the input size, use 'input' command\n\n");
        }

    } while (inputSize <= 0 || inputSize > MAX_INPUT_SIZE);

    return inputSize;
}

void randomArrayGenerator(int array[], int size) 
{
    

    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % (size * 10) + 1; 
    }

    printf("Array created successfully and randomly\n\n");
}

void arrayCloner(int array[], int temp[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        temp[i] = array[i];
    }
}

void arrayPrinter(int array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void endOfAlgorithm(int temp[], int size) 
{
    int choice;

    while (1)
    {
        printf("[1] Go back to menu  [2] Show 'sorted' array : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            break;
        }
        else if (choice == 2)
        {
            arrayPrinter(temp, size); 
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int hold = *a;
    *a = *b;
    *b = hold;
}


void insertionSort(int temp[], int size) 
{
    printf("main > Insertion Sort > Loading...");
    fflush(stdout);
    clock_t start, end;
    int i, k, key;

    start = clock();

    for (i = 1; i < size; i++) 
    {
        key = temp[i];
        for (k = i - 1; k >= 0 && key <= temp[k]; k--)
        {
            temp[k + 1] = temp[k];
        }
        temp[k + 1] = key;
    }
    end = clock();

    printf("\n\n-> The running time of Insertion Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, size);
}

void selectionSort(int temp[], int size) 
{
    printf("main > Selection Sort > Loading...");
    fflush(stdout);
    clock_t start, end;
    int i, j, min_idx; 

    start = clock();

    for (i = 0; i < size - 1; i++) 
    {
        min_idx = i; 
        for (j = i + 1; j < size; j++) 
        {
            if (temp[j] < temp[min_idx])
            {
                min_idx = j; 
            }
        }

        if (min_idx != i)
        {
            swap(&temp[min_idx], &temp[i]);
        }
    }

    end = clock();
    printf("\n\n-> The running time of Selection Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, size);
}

void bubbleSort(int temp[], int size) 
{
    printf("main > Bubble Sort > Loading...");
    fflush(stdout);
    clock_t start, end;
    int i, j, key; 

    start = clock();

    for (j = 0; j < size - 1; j++) 
    {
        for (i = 0; i < size - 1 - j; i++) 
        {
            if (temp[i] > temp[i + 1])
            {
                key = temp[i];
                temp[i] = temp[i + 1];
                temp[i + 1] = key;
            }
        }
    }
    end = clock();

    printf("\n-> The running time of Bubble Sort algorithm is : %.6f in seconds (Input Size: %d)\n\n", (double)(end - start) / CLOCKS_PER_SEC, size);
}

void mergeSort(int temp[], int left, int right)
{
    int k;

    if (left < right)
    {
        k = (left + right) / 2;

        mergeSort(temp, left, k);
        mergeSort(temp, k + 1, right);

        merge(temp, left, k, right);
    }
}

void merge(int temp[], int left, int k, int right)
{
    int i, j, l = 0;
    
    int *M_local = (int *)malloc(sizeof(int) * (right - left + 1));
    if (M_local == NULL) {
        perror("Error allocating memory for 'M_local' in merge function");
        exit(EXIT_FAILURE);
    }

    for (i = left, j = k + 1; (i <= k) && (j <= right);)
    {
        if (temp[i] < temp[j])
        {
            M_local[l] = temp[i];
            i++;
            l++;
        }
        else
        {
            M_local[l] = temp[j];
            j++;
            l++;
        }
    }

    while (i <= k)
    {
        M_local[l] = temp[i];
        i++;
        l++;
    }

    while (j <= right)
    {
        M_local[l] = temp[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++)
    {
        temp[i] = M_local[l];
    }
    free(M_local); 
}

void quickSort(int temp[], int first, int last)
{
    int i, j, pivot, hold;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (temp[i] <= temp[pivot] && i < last)
            {
                i++;
            }

            while (temp[j] > temp[pivot])
            {
                j--;
            }

            if (i < j)
            {
                hold = temp[i];
                temp[i] = temp[j];
                temp[j] = hold;
            }
        }

        hold = temp[pivot];
        temp[pivot] = temp[j];
        temp[j] = hold;

        quickSort(temp, first, j - 1);
        quickSort(temp, j + 1, last);
    }
}

void heapify(int temp[], int size, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && temp[left] > temp[largest]) 
    {
        largest = left;
    }

    if (right < size && temp[right] > temp[largest]) 
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&temp[i], &temp[largest]);
        heapify(temp, size, largest); 
    }
}

void heapSort(int temp[], int size) 
{
    for (int i = size / 2 - 1; i >= 0; i--) 
    {
        heapify(temp, size, i); 
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        swap(&temp[0], &temp[i]);
        heapify(temp, i, 0); 
    }
}