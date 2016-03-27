/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int string_compare1(char *, char *);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
	return NULL;
	int i = 0, j = 0,p,count=0;
	struct transaction *C;
	C = (struct transaction *)malloc(sizeof(struct transaction));
	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			p = string_compare1(A[i].date,B[j].date);
			if (p == 0){
				C = A;
				count++;
			}
		}
	}
	if (count == 0)
		return NULL;
	else
	return C;
}
int string_compare1(char *a, char *b){
	int i = 0, temp1 = 0;
	while (a[i] != '\0'){
		if (a[i] == b[i])
			temp1++;
		i++;
	}
	if (i == temp1)
		return 0;
	else
		return 1;
}
