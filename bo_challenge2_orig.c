#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Account {
  char *name;
  char *password;
  int secret_number;
};

#define MAX_ATTEMPTS 3


int check_account_exists(char *account_name, struct Account *accounts, int num_accounts) {
  bool account_exists = false;
  int account_index = -1;
  int i = 0;
  while (i < num_accounts) {
    printf("1 %s\n2 %s\n", accounts[0].name, account_name);
    if (strcmp(accounts[i].name, account_name) == 0) {
      account_exists = true;
      account_index = i;
      return account_index;
    }
    i++;
  }
  return -1;
  
}

int sign_up(int num_accounts, struct Account *accounts) {


  return 0;
}

bool login(struct Account *accounts, int num_accounts) {
  char account_name[21];
  printf("Login Page.\n");
  printf("Please enter your account name:\n");
  scanf("%s", account_name);
  int account_index = check_account_exists(account_name, accounts, num_accounts);
  char password[21];
  printf("Please enter your password:\n");
  scanf("%s", password);
  if (account_index != -1 && strcmp(password, accounts[account_index].password) == 0) {
    return true;
  }
  printf("Incorrect login details.\n");
  return false;
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
  // This is created with the assumption that variables are 
  // stored next to each other, even if they're not.
  // Failed login attempts, after 3 attempts you have the option 
  // to reset your password.
  
  char default_password[10] = "hello";
  char password[10];
  strcpy(password, default_password);

  char admin_ps[7] = "8uFF3R";
  struct Account accounts[21] = {"\0"};
  int num_accounts = 0;

  char has_account = 'I';
  while (1) {
    if (num_accounts == 20) {
      has_account = 'Y';
    } else if (num_accounts > 0) {
      printf("Welcome! Do you already have an account? Enter Y or N\n");
      scanf("%s", &has_account);
      while (has_account != 'Y' && has_account != 'N') {
        printf("Invalid Response, please try again.\n");
        scanf("%s", &has_account);
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
          printf("You must now reset your password.");
          printf("Please enter your account name:\n");
          reset_password(accounts, num_accounts);
          printf("New Password:\n");
          scanf("%s", &password);
          printf("You have reset your password!");        
        }
        login_status = login(accounts, num_accounts);
        num_attempts++;
      }
      printf("You logged in!\n");
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
      char password[10];
      printf("Please enter a password: ");
      scanf("%s", &password);

      accounts[num_accounts].name = account_name;
      accounts[num_accounts].password = password;

      printf("Account with username %s created! Returning to homepage.\n", accounts[num_accounts].name);
      num_accounts++;
    }
  }
  

  return 0;
}