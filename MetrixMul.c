 #include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Each thread computes a single element in the resultant matrix
void* multiplication(void* arg) {
    int* data = (int*)arg;
    int k = 0, i = 0;

    int x = data[0];
    for (i = 1; i <= x; i++)
        k += data[i] * data[i + x];

    int* p = (int*)malloc(sizeof(int));
    *p = k;

    // Used to terminate a thread and the return value is passed as a pointer
    pthread_exit(p);
}

// Driver code
int main() {

    int MAX;
    printf("Enter the size of matrices: ");
    scanf("%d", &MAX);

    int matA[MAX][MAX];
    int matB[MAX][MAX];

    int r1 = MAX, c1 = MAX, r2 = MAX, c2 = MAX, i, j, k;

    // Requesting values for matA from the user
    printf("Enter values for MATRIX A (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matA[i][j]);
        }
    }

    // Requesting values for matB from the user
    printf("Enter values for MATRIX B (%dx%d):\n", r2, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matB[i][j]);
        }
    }

    // Displaying matA
    printf("MATRIX A :- \n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%d ", matA[i][j]);
        printf("\n");
    }

    // Displaying matB
    printf("MATRIX B :- \n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", matB[i][j]);
        printf("\n");
    }

    int max = r1 * c2;

    // Declaring array of threads of size r1*c2
    pthread_t* threads = (pthread_t*)malloc(max * sizeof(pthread_t));

    int count = 0;
    int* data = NULL;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            // Storing row and column elements in data
            data = (int*)malloc((20) * sizeof(int));
            data[0] = c1;

            for (k = 0; k < c1; k++)
                data[k + 1] = matA[i][k];

            for (k = 0; k < r2; k++)
                data[k + c1 + 1] = matB[k][j];

            // Creating threads
            pthread_create(&threads[count++], NULL, multiplication, (void*)(data));
        }
    }

    // Printing the result
    printf("A x B MATRIX :- \n");
    for (i = 0; i < max; i++) {
        void* k;

        // Joining all threads and collecting return value
        pthread_join(threads[i], &k);

        int* p = (int*)k;
        printf("%d ", *p);
        if ((i + 1) % c2 == 0)
            printf("\n");

        // Freeing the allocated memory for the result
        free(p);
    }

    // Freeing allocated memory for threads
    free(threads);

    return 0;
}
