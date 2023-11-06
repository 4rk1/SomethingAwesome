#include <stdio.h>

int main(void) {
  char name[10];
  char show_hash_type = 'N';
  printf("What's your name?\n");
  fgets(name, 20, stdin);
  for (int i = 0; i < 10; i++) {
    if (name[i] == '\n' || i == 9) {
      name[i] = '\0';
    }
  }
  printf("\nWelcome to %s's password manager!\n", name);
  printf("\n'show_hash_type' is set to %c\n", show_hash_type);
  if (show_hash_type == 'Y') {
    printf("Hash type is U2hhMi0yNTY=\n");
  }
  printf("\nYour encrypted password is FDDBB38A8C0C18B628A066436F44C84B57931307F274B62255E96D50D8627B8F\n");
  return 0;
}