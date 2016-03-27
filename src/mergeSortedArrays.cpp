/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
using namespace std;
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int index1 = 0, index2 = 0, p = 0, temp = 0;
	struct transaction *output;
	output = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int YYYY1[4], YYYY2[4];
	while (index1 < ALen && index2 <BLen){
			{
				int  Year1 = 0, Year2 = 0, k = 0;
				YYYY1[0] = A[index1].date[6] - '0';
				YYYY1[1] = A[index1].date[7] - '0';
				YYYY1[2] = A[index1].date[8] - '0';
				YYYY1[3] = A[index1].date[9] - '0';
				for (k = 0; k < 4; k++)
					Year1 = 10 * Year1 + YYYY1[k];
				YYYY2[0] = B[index2].date[6] - '0';
				YYYY2[1] = B[index2].date[7] - '0';
				YYYY2[2] = B[index2].date[8] - '0';
				YYYY2[3] = B[index2].date[9] - '0';
				for (k = 0; k < 4; k++)
					Year2 = 10 * Year2 + YYYY2[k];
				if (Year1 >Year2){
					output[temp] = B[index2];
					temp++;
					index2++;
				}
				else{
					output[temp] = A[index1];
					temp++;
					index1++;
				}
			}
	}
	while (index1<ALen){
		output[temp] = A[index1];
		temp++;
		index1++;
	}
	while (index2<BLen){
		output[temp] = B[index2];
		temp++;
		index2++;
	}
	return output;
}