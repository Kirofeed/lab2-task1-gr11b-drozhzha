/* main.c
 * Author: Kiryl Drozhzha
 * Description: Program that implements three tasks:
 *   1. Print perfect squares from an array of natural numbers.
 *   2. Manage NOTE1 records: input, sort by initials, and display records by birth month.
 *   3. Manage Worker records: input and display workers employed in 2020.
 * Date: 2025-03-10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 9
#define WORKER_SIZE 3

/* Structure for Date */
typedef struct {
		int year;
		int month;
		int day;
} Date;

/*
 * Function: isPerfectSquare
 * ----------------------------
 * Checks if a given natural number is a perfect square.
 *
 * num: the number to check.
 *
 * Returns:
 *    1 if num is a perfect square, 0 otherwise.
 */
int isPerfectSquare(int num) {
	if (num < 0)
		return 0;
	int root = (int) sqrt(num);
	return (root * root == num);
}

/* Task 1: Print perfect squares from an array of natural numbers */
void task1() {
		int n;
		printf("Task 1: Perfect Squares\n");
		printf("Enter the number of elements: ");
		scanf("%d", &n);
		if (n <= 0) {
				printf("Invalid number of elements.\n");
				return;
		}
		int *array = (int *) malloc(n * sizeof(int));
		if (array == NULL) {
				printf("Memory allocation failed.\n");
				return;
		}
		printf("Enter %d natural numbers:\n", n);
		for (int i = 0; i < n; i++) {
				scanf("%d", &array[i]);
		}
		printf("Perfect squares in the array:\n");
		int found = 0;
		for (int i = 0; i < n; i++) {
				if (isPerfectSquare(array[i])) {
						printf("%d ", array[i]);
						found = 1;
				}
		}
		if (!found)
				printf("No perfect squares found.");
		printf("\n\n");
		free(array);
}

/* Structure NOTE1 for Task 3 */
typedef struct {
		char name[50];   // фамилия и инициалы
		char tele[20];   // номер телефона
		Date date;       // дата рождения
} NOTE1;

/* Compare function for qsort to sort NOTE1 by name */
int compareNote1(const void *a, const void *b) {
		NOTE1 *noteA = (NOTE1 *) a;
		NOTE1 *noteB = (NOTE1 *) b;
		return strcmp(noteA->name, noteB->name);
}

void main (void)
{
	printf ("Hello World\n");
	printf ("Goodbye World\n");
}
