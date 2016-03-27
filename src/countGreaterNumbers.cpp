/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int string_compare(char *,char *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0,count=0,count1=0,p,q=0;
	for (i = 0; i < len; i++){
		p = string_compare(date, Arr[i].date);
		if (p == 0){
			count++;
			q = i;
		}
		else
			count1++;
	}
	if (len == count || count == 0)
		return 0;
	else 
		return len-1-q;
}
int string_compare(char *date, char *a){
	int i = 0, temp1 = 0;
	while (date[i] != '\0'){
		if (date[i] == a[i])
			temp1++;
		i++;
	}
	if (i == temp1)
		return 0;
	else
		return 1;
}
