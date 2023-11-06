#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This was originally written in Python but then I realised I only wanted users to have access to the executable
// So, I converted it C with the help of an online tool to speed up the process (although in the end it was a bit of a pain)

void show_conversation() {
  printf("Richard: Hey Callum - or was it Kris? - have you fixed this week's wargame yet?\n");
  printf("Kris: Yeah I think it should work now. Just stuck on what to make the flag. Any ideas?\n");
  printf("Richard: I do have an idea, I'll send it through\n");
  printf("Kris: Wait, what if someone manages to intercept this message?\n");
  printf("Richard: Oh, you're right, I'll encode it using the merkle's puzzles you sent me, those are pretty secure\n");
  printf("Richard: Ok, here's the message encrypted with a Vigenère cipher: FKVYSFJ, I used the key from the message containing 8\n");
  printf("Kris: Thank you, I'll upload the wargame once I'm done\n");
}

int main(void) {
  
  char *messages[] = {"khoor pb QDPH lv wzhoyh", "rcvo dn ocmzz HZVIDIB ja ocdn", "fhecevfr gur JNETNZR oebxr avar", "r mx wxc twxf qxf cfx farcn LXMN", "clyozx hzcod xlop qzfc QTWWPC", "ai evi tpecmrk FMRKS rsa, pikw ipizir", "hgx wtr b PBEE extox axkx", "zogh kssy kog gdccym psqoigs wh kog TFWROM cqhcpsf hvwfhssb", "n ktzsi f knaj ITQQFW styj ts ymj lwtzsi", "lhfxmbfxl b YHKZXM patm b xbzam yhk ukxtdytlm", "u imfotqp m YAHUQ mnagf ftq eqhqz pqmpxk euze", "y jud je VYDT yj xqht dej je fheshqijydqju", "ISXEEB yi xqht vekhjuud", "se lgbuaxozk TASHKX oy lolzkkt", "hxm pcs HIDCTH bpn qgtpz bn qdcth"};
  printf("Intercepted Data Between Richard and Kris\n");

  while (1) {
    char user_input[100];
    printf("Enter command: ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';

    char *words[10];
    int num_words = 0;
    char *separated = strstr(user_input, " ");
    if (separated) {
      char *token = strtok(user_input, " ");
      while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
      }
    } else if (strcmp(user_input, "") != 0) {
      words[0] = user_input;
      num_words = 1;
    }
    char *command = malloc(100 * sizeof(char));
    char *argument = malloc(100 * sizeof(char));
    if (num_words > 2 || num_words == 0) {
        printf("Invalid Input. Please enter another command.\n");
        printf("For information on all available commands, type 'HELP'\n");
        continue;
    } else if (num_words == 2) {
        command = words[0];
        argument = words[1];
    } else {
        command = words[0];
        argument = "";
    }

    printf("\n");
    if (strcmp(command, "HELP") == 0 && num_words == 1) {
        printf("LIST\n\tLists the ids of all intercepted encrypted messages\n");
        printf("\nSHOW (message_id)\n\tDisplays the contents of encrypted message with id (message_id). If no name is given it will print the unencrypted conversation between Richard and Kris\n");
    } else if (strcmp(command, "LIST") == 0) {
        for (int i = 1; i <= 15; i++) {
            printf("%d\n", i);
        }
    } else if (strcmp(command, "SHOW") == 0) {
      if (strcmp(argument, "") != 0 && atoi(argument) != 0 && atoi(argument) <= 15) {
        printf("%s\n", messages[atoi(argument) - 1]);
      } else if (num_words == 1) {
          show_conversation();
      } else {
        printf("Invalid Input. Please enter another command.\n");
        printf("For information on all available commands, type 'HELP'\n");
      }
    } else {
        printf("Invalid Input. Please enter another command.\n");
        printf("For information on all available commands, type 'HELP'\n");
    }
    printf("\n");
  }
  return 0;
}