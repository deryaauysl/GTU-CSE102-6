#include <stdio.h> /*DEĞİŞTİRDİK İNCİ HOCAYLA DÜZELDİ*/

int a, b; /* Global variables */

/* Function to count, store and create histogram of numbers within the appropriate range */
int find_size_of_array(int A[])
{
    int size = 0;
    int i, j;
    int count[201] = {0}; /* Array to hold the number of repetitions of each number (50-200 range) */
    int max_count = 0;    /* Number of repetitions of the most repeated number */

    /* Calculate the number of repetitions and find the maximum number of repetitions */
    for (i = 0; A[i] != -1; i++)
    {
        if (A[i] >= a && A[i] <= b)
        {
            size++;
        }
    }

    /* Draw the histogram (horizontal, without repetition numbers and numbers) */
    for (i = max_count; i > 0; i--)
    {                /* From the highest value to 1 (y-axis) */
        printf(" "); /* 2 spaces (y-axis) */
        for (j = 0; j <= b - a; j++)
        { /* For each number (x-axis) */
            if (count[j] >= i)
            {
                printf("*"); /* Print a star if the number of repetitions is sufficient */
            }
            else
            {
                printf(" "); /* Otherwise, leave a space */
            }
        }
        printf("\n"); /* End of line */
    }
    return size;
}

/* Function to calculate the average */
double calculate_average(int A[], int size)
{
    int sum = 0;
    int count = 0;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (A[i] >= a && A[i] <= b)
        {
            sum += A[i];
            count++;
        }
    }
    return (double)sum / count;
}

/* Function to calculate the mode */
void calculate_mode(int A[], int size)
{
    int count[201] = {0};
    int max_count = 0;
    int mode_count = 0;
    int i = 0;

    /* Calculate the number of repetitions and find the maximum number of repetitions */
    for (i = 0; i < size; i++)
    {
        if (A[i] >= a && A[i] <= b)
        {
            count[A[i] - a]++;
            if (count[A[i] - a] > max_count)
            {
                max_count = count[A[i] - a];
            }
        }
    }

    /* Find and print the mode values */
    printf("Mode: ");
    for (i = 0; i <= b - a; i++)
    {
        if (count[i] == max_count)
        {
            printf("%d ", i + a);
            mode_count++;
        }
    }
    if (mode_count == 0)
    {
        printf("No mode");
    }
    printf("\n");
}

/* Function to calculate the median */
double calculate_median(int A[], int size)
{
    int i = 0;
    int j = 0;

    /* Sort the array (bubble sort) */
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    /* Calculate the median */
    if (size % 2 == 0)
    {
        /* If there is an even number of elements, take the average of the middle two elements */
        return (double)(A[(size / 2) - 1] + A[size / 2]) / 2;
    }
    else
    {
        /* If there is an odd number of elements, take the middle element */
        return (double)A[size / 2];
    }
    int k = 0;

    for (k = 0; k < size; k++)
    {
        printf("%d", A[k]);
    }
}

int main()
{
    int flag = 1;
    int size = 0;
    int i = 0;
    int number_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};

    while (flag)
    {
        printf("Enter A and B values:");
        scanf("%d %d", &a, &b);
        if (a < 0 || b > 200 || a > b)
        {
            printf("Invalid range. Please try again.\n");
        }
        else
        {
            flag = 0;
        }
    }

    size = find_size_of_array(number_array);

    /* Part 2: Update the histogram */
    char choice;
    printf("Would you like to add new numbers? (Press 1 for yes, Press 0 for no): ");
    scanf(" %c", &choice);

    int new_numbers[5];
    int num_count = 0;
    printf("Enter the numbers:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &new_numbers[i]);
        if (new_numbers[i] == -1)
        {
            break;
        }
        num_count++;
    }

    int new_size = size + num_count;
    int new_number_array[new_size + 1];

    if (choice == '1')
    {
        /* Add new numbers to the array */

        for (i = 0; i < size; i++)
        {
            new_number_array[i] = number_array[i];
        }
        for (i = 0; i < num_count; i++)
        {
            new_number_array[size + i] = new_numbers[i];
        }
        new_number_array[new_size] = -1; /* Terminator */

        /* Draw the histogram with the updated array */
        size = find_size_of_array(new_number_array);
    }

    /* Part 3: Calculate average, mode and median */
    if (size > 0)
    {
        double average = calculate_average(new_number_array, size);
        printf("Average: %.2lf\n", average);

        double median = calculate_median(new_number_array, size);
        printf("Median: %.2lf\n", median);

        calculate_mode(number_array, size);
    }
    else
    {
        printf("Array is empty, statistics cannot be calculated.\n");
    }

    return 0;
}