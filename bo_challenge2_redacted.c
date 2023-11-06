#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Account {
  char name[21];
  char password[21];
  int secret_number;
};

#define MAX_ATTEMPTS 3


int check_account_exists(char *account_name, struct Account *accounts, int num_accounts) {
  bool account_exists = false;
  int account_index = -1;
  int i = 0;
  while (i < num_accounts) {
    if (strcmp(accounts[i].name, account_name) == 0) {
      account_exists = true;
      account_index = i;
      return account_index;
    }
    i++;
  }
  return -1;
  
}

int reset_password(struct Account *accounts, int num_accounts) {
  char account_name[21];
  scanf("%s", &account_name);
  bool account_exists = false;
  int account_index = -1;
  while (!account_exists) {
    account_index = check_account_exists(account_name, accounts, num_accounts);
    if (account_index != -1) {
      account_exists = true;
    }
    if (!account_exists) {
      printf("This account does not exist. Please enter another name:\n");
      scanf("%s", &account_name);
    }
  }

  return account_index;
}

int main(void) {
  char admin_nm[6] = "admin";
  char admin_ps[7];
  char password[10];
  struct Account accounts[21];
  int num_accounts = 0;

  while (1) {
    char has_account = 'I';
    if (num_accounts == 20) {
      has_account = 'Y';
    } else if (num_accounts > 0) {
      printf("\nWelcome! Do you already have an account? Enter Y or N\n");
      scanf(" %c", &has_account);
      while (has_account != 'Y' && has_account != 'N') {
        printf("Invalid Response, please try again.\n");
        scanf(" %c", &has_account);
      }
    } else {
      has_account = 'N';
    }
    
    if (has_account == 'Y') {
      int num_attempts = 0;
      bool login_status = false;
      while (!login_status) {
        if (num_attempts == MAX_ATTEMPTS) {
          printf("You have reached the maximum number of login attempts.\n");
          printf("You must now reset your password. Please enter your account name:\n");
          int old_account_index = reset_password(accounts, num_accounts);
          printf("New Password (max 10 characters):\n");
          scanf("%s", &password);
          strcpy(accounts[old_account_index].password, password);
          printf("You have reset your password!\n");        
        }
        char login_name[21];
        printf("Login Page.\n");
        printf("Please enter your account name:\n");
        scanf("%s", login_name);
        int account_index;
        account_index = check_account_exists(login_name, accounts, num_accounts);
        char login_password[21];
        printf("Please enter your password:\n");
        scanf("%s", login_password);
        if (account_index != -1 && strcmp(login_password, accounts[account_index].password) == 0) {
          login_status = true;
          printf("You logged in!\n");
          printf("Your secret number was %d.\n", accounts[account_index].secret_number);
          printf("Now logging out for security purposes.\n");
        } else {
          printf("Incorrect login details.\n");
        }
        num_attempts++;

      }
    } else if (has_account == 'N') {
      // sign_up(num_accounts, accounts);
      // Initially I had this separate function but it was too much work
      // trying to deal with pointers
      printf("It's time to make your account!\n");
      printf("Please enter an account_name:\n");
      char account_name[21];
      scanf("%s", &account_name);
      while (check_account_exists(account_name, accounts, num_accounts) != -1) {
        printf("This name is taken. Please enter another name:\n");
        scanf("%s", &account_name);
      }
      char account_password[11];
      printf("Please enter a password (max 10 characters):\n");
      scanf("%s", &account_password);

      printf("Please enter your secret number:\n");
      int secret_number;
      scanf("%d", &secret_number);

      strcpy(accounts[num_accounts].name, account_name);
      strcpy(accounts[num_accounts].password, account_password);
      accounts[num_accounts].secret_number = secret_number;

      num_accounts++;
    }
  }
  

  return 0;
}
