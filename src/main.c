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

/* Task 3: Manage NOTE1 records */
void task3() {
		NOTE1 block[BLOCK_SIZE];
		int targetMonth;
		int i;

		printf("Task 3: NOTE1 Records\n");
		printf("Enter information for %d NOTE1 records:\n", BLOCK_SIZE);
		for (i = 0; i < BLOCK_SIZE; i++) {
				printf("\nRecord %d:\n", i + 1);
				printf("Enter name (surname and initials): ");
				scanf(" %[^\n]s", block[i].name);
				printf("Enter telephone number: ");
				scanf(" %[^\n]s", block[i].tele);
				printf("Enter birth date (year month day): ");
				scanf("%d %d %d", &block[i].date.year, &block[i].date.month, &block[i].date.day);
		}

		/* Sort records by name */
		qsort(block, BLOCK_SIZE, sizeof(NOTE1), compareNote1);

		printf("\nEnter target birth month: ");
		scanf("%d", &targetMonth);

		int found = 0;
		printf("\nNOTE1 records with birth month %d:\n", targetMonth);
		for (i = 0; i < BLOCK_SIZE; i++) {
				if (block[i].date.month == targetMonth) {
						printf("Name: %s, Telephone: %s, Birth Date: %d-%02d-%02d\n", 
									 block[i].name, block[i].tele, block[i].date.year, block[i].date.month, block[i].date.day);
						found = 1;
				}
		}
		if (!found)
				printf("No records found for the specified month.\n");

		printf("\n");
}

/* Structure for Address used in Worker */
typedef struct {
		char postalCode[10];
		char country[30];
		char region[30];
		char district[30];
		char city[30];
		char street[30];
		char house[10];
		char apartment[10];
} Address;

/* Structure Worker for Task 4 */
typedef struct {
		char surname[30];
		char name[30];
		char patronymic[30];
		Address address;
		char nationality[30];
		Date birthDate;
		int shopNumber;
		int employeeNumber;
		char education[50];
		int yearEmployment;
} Worker;

/* Task 4: Manage Worker records */
void task4() {
		Worker workers[WORKER_SIZE];
		int i;

		printf("Task 4: Worker Records\n");
		printf("Enter information for %d workers:\n", WORKER_SIZE);
		for (i = 0; i < WORKER_SIZE; i++) {
				printf("\nWorker %d:\n", i + 1);
				printf("Enter surname: ");
				scanf(" %[^\n]s", workers[i].surname);
				printf("Enter name: ");
				scanf(" %[^\n]s", workers[i].name);
				printf("Enter patronymic: ");
				scanf(" %[^\n]s", workers[i].patronymic);

				printf("Enter address details:\n");
				printf("Postal Code: ");
				scanf(" %[^\n]s", workers[i].address.postalCode);
				printf("Country: ");
				scanf(" %[^\n]s", workers[i].address.country);
				printf("Region: ");
				scanf(" %[^\n]s", workers[i].address.region);
				printf("District: ");
				scanf(" %[^\n]s", workers[i].address.district);
				printf("City: ");
				scanf(" %[^\n]s", workers[i].address.city);
				printf("Street: ");
				scanf(" %[^\n]s", workers[i].address.street);
				printf("House: ");
				scanf(" %[^\n]s", workers[i].address.house);
				printf("Apartment: ");
				scanf(" %[^\n]s", workers[i].address.apartment);

				printf("Enter nationality: ");
				scanf(" %[^\n]s", workers[i].nationality);
				printf("Enter birth date (year month day): ");
				scanf("%d %d %d", &workers[i].birthDate.year, &workers[i].birthDate.month, &workers[i].birthDate.day);
				printf("Enter shop/workshop number: ");
				scanf("%d", &workers[i].shopNumber);
				printf("Enter employee number: ");
				scanf("%d", &workers[i].employeeNumber);
				printf("Enter education: ");
				scanf(" %[^\n]s", workers[i].education);
				printf("Enter year of employment: ");
				scanf("%d", &workers[i].yearEmployment);
		}

		printf("\nWorkers employed in 2020:\n");
		int found = 0;
		for (i = 0; i < WORKER_SIZE; i++) {
				if (workers[i].yearEmployment == 2020) {
						printf("Name: %s %s %s, Nationality: %s, Birth Date: %d-%02d-%02d\n",
									 workers[i].surname, workers[i].name, workers[i].patronymic,
									 workers[i].nationality, workers[i].birthDate.year, workers[i].birthDate.month, workers[i].birthDate.day);
						printf("Address: %s, %s, %s, %s, %s, %s, %s, %s\n",
									 workers[i].address.postalCode, workers[i].address.country, workers[i].address.region,
									 workers[i].address.district, workers[i].address.city, workers[i].address.street,
									 workers[i].address.house, workers[i].address.apartment);
						printf("Shop Number: %d, Employee Number: %d, Education: %s, Year of Employment: %d\n\n",
									 workers[i].shopNumber, workers[i].employeeNumber, workers[i].education, workers[i].yearEmployment);
						found = 1;
				}
		}
		if (!found)
				printf("No workers employed in 2020 were found.\n");

		printf("\n");
}

int main(void)
{
		task1();
		task3();
		task4();
		return 0;
}