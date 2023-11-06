#include <stdio.h>

int main(void) {
  char name[10];
  
  char _true = 'T';
  char _false = 'F';

  printf("What's your name? ");
  // Want to leave a lot of space just in case people have long names :)
  fgets(name, 100, stdin);
  
  if (_true == _false) {
    win();
  } else {
    printf("Well hello %s", name);
  }

  return 0;
}
