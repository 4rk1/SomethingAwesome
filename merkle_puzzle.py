#!/usr/bin/env python3

def show_conversation():
  print("Richard: Hey Kris have you fixed this week's wargame yet?")
  print("Kris: Yeah I think it should work now. Just stuck on what to make the flag. Any ideas?")
  print("Richard: I do have an idea, I'll send it through")
  print("Kris: Wait, what if someone manages to intercept this message?")
  print("Richard: Oh, you're right, I'll encode it using the merkle puzzle you sent me, those are pretty secure")
  print("Richard: Ok, here's the encrypted message AHEUCNDEIL, I used the key from the message containing 8")
  print("Kris: Thank you, I'll upload the wargame once I'm done")


messages = ["khoor pb QDPH lv wzhoyh", "rcvo dn ocmzz HZVIDIB ja ocdn", "fhecevfr gur JNETNZR oebxr avar", "r mx wxc twxf qxf cfx farcn LXMN", "clyozx hzcod xlop qzfc QTWWPC", "ai evi tpecmrk FMRKS rsa, pikw ipizir", "hgx wtr b PBEE extox axkx", "zogh kssy kog gdccym psqoigs wh kog TFWROM cqhcpsf hvwfhssb", "n ktzsi f knaj ITQQFW styj ts ymj lwtzsi", "lhfxmbfxl b YHKZXM patm b xbzam yhk ukxtdytlm", "u imfotqp m YAHUQ mnagf ftq eqhqz pqmpxk euze", "y jud je VYDT yj xqht dej je fheshqijydqju", "ISXEEB yi xqht vekhjuud", "se lgbuaxozk TASHKX oy lolzkkt", "hxm pcs HIDCTH bpn qgtpz bn qdcth"]

print("Intercepted Data Between Richard and Kris")
while (1):
  user_input = input("Enter command: ")
  words = user_input.split(" ")

  if len(words) > 2 or len(words) == 0:
    print("Invalid Input. Please enter another command.")
    print("For information on all available commands, type 'HELP'")
    continue
  elif len(words) == 2:
    command = words[0]
    argument = words[1]
  else:
    command = words[0]
    argument = ""

  if command == "HELP":
    print("LIST\n\tLists the ids of all intercepted encrypted messages\n")
    print("SHOW (message_id)\n\tDisplays the contents of encrypted message with id (message_id). If no name is given it will print the unencrypted conversation between Richard and Kris\n")
  elif command == "LIST":
    for i in range(1, 16):
      print(i)
  elif command == "SHOW":
    if argument:
      print(messages[int(argument) - 1])
    else:
      show_conversation()
  else:
    print("Invalid Input. Please enter another command.")
    print("For information on all available commands, type 'HELP'")



  