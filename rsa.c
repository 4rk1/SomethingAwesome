#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

// Converts integer into a string
// Sourced at this link: https://www.reddit.com/r/learnprogramming/comments/oug0bw/writing_itoa_in_c/
char* itoa(int n, char* buff) {
	int i = 0, d, n2 = n;

	while (n2 > 9) {
		d = 0;
		while (n > 9) {
			n /= 10;
			d++;
		}
		buff[i] = n + '0';
		i++;
		n2 -= (pow(10, d) * n); 
	}
	buff[i] = (n2 % 10)+'0';
	i++;
	buff[i] = '\0';

	return buff;
}

int main(void) {
  printf("Welcome to RSAB\nSouth Africa's Premier Bank\n\n");
  printf("Forgot Password:\nWould you like to reset your password? (Y or N)\n\n");
  char response;
  scanf(" %c", &response);  
  printf("\n");
  while (response != 'Y' && response != 'N') {
    printf("Invalid response\nPlease try again.\n");
    scanf(" %c", &response);
  }

  if (response == 'N') {
    printf("Thank you for your visit to RSAB\n");
    return 0;
  }

  char *origfilename = malloc(12 * sizeof(char));
  char *filename = malloc(12 * sizeof(char));
  strcpy(origfilename, "RSAB");
  strcpy(filename, "RSAB.txt");
  char *istr = malloc(12 * sizeof(char));
  int i = 0;

  // Had to test the access function to find out what it returns.
  while (access(filename, F_OK) != -1 && i < 100) {
    strcpy(filename, origfilename);
    strcpy(istr, itoa(i, istr));
    strcat(filename, istr);
    strcat(filename, ".txt");
    i++;
  }

  if (i == 100) {
    printf("Sorry, unable to send recovery email. Password was not reset.\n");
    return 0;
  }

  FILE *file = fopen(filename, "w");
  char email[] = "Local Account Number: 3456054995\nInterest Earned: R10000\nCurrent Balance: R1299949\nNew Password (Encrypted): 54244227711";
  fwrite(email, 1, sizeof(email) - 1, file);
  fclose(file);
  printf("Password reset.\nNew password has been encrypted and sent to your account email (current directory)\n");
}