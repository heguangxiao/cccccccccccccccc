#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern float **fmatrix(int m, int n);

enum
{
    HDRS = 5,
    ROWS = 10,
    COLS = 5
};

static int read_line(FILE *ifp, char *buffer, size_t buflen)
{
    if (fgets(buffer, buflen, ifp) == 0)
    {
        fprintf(stderr, "EOF\n");
        return 0;
    }
    size_t len = strlen(buffer);
    buffer[len - 1] = '\0';
    printf("[[%s]]\n", buffer);
    return 1;
}

int main(void)
{
    FILE *ifp;
    char mystring[500];
    int i, j, n;

    ifp = stdin;
    if (ifp != NULL)
    {
        // Test with COLS result blocks each containing ROWS frequency values
        float **A = fmatrix(ROWS, COLS);
        for (j = 0; j < COLS; j++)
        {
            // using fgets w/ printf to see contents of "discarded" lines
            for (i = 0; i < HDRS; i++)
            {
                if (read_line(ifp, mystring, sizeof(mystring)) == 0)
                    break;
            }

            for (i = 0; i < ROWS; i++)
            {
                // skip over first float, store the next float into A[i][j]
                if (read_line(ifp, mystring, sizeof(mystring)) == 0)
                    break;
                if ((n = sscanf(mystring, " %*e %E", &A[i][j])) != 1)
                    break;
                printf("A[%i][%i]: %E, %i\n", i, j, A[i][j], n);
            }
        }

        for (i = 0; i < ROWS; i++)
        {
            for (j = 0; j < COLS; j++)
                printf("%8.3f", A[i][j]);
            putchar('\n');
        }
    }
    return 0;
}

float **fmatrix(int m, int n)
{
    // Return an m x n Matrix
    int i;
    float **A = (float **)malloc(m * sizeof(float *));
    A[0] = (float *)malloc(m * n * sizeof(float));
    for (i = 1; i < m; i++)
    {
        A[i] = A[i - 1] + n;
    }
    return A;
}