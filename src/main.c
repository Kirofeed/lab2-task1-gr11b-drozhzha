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

void main (void)
{
	printf ("Hello World\n");
	printf ("Goodbye World\n");
}
