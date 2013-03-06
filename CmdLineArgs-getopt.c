/* Copyright (C) 2012 Arpan, All Rights Reserved */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SWVER "SV01RV01"

void printUsage() 
{
  printf("Usage: A-App [-h] [-z] [-n value] [-s string]\n");
  printf("-h\t this help\n");
  printf("-v\t print version\n");
  printf("-z\t display zero arguement\n");
  printf("-n\t display a value\n");
  printf("-s\t display a string\n");
}

int main (int argc, char **argv)
{
  int opt = 0;
  char *str = NULL;

  printf("Copyright (C) 2012 Arpan, All Rights Reserved.\n");

  while ((opt = getopt(argc, argv, "zhvn:s:")) != -1) {
    switch (opt) {
      case 'h':
        printf("Help...\n");
        printUsage();
        exit(0);
        break;
      case 'v':
        printf("Version: %s\n", SWVER);
        exit(0);
        break;
      case 'z':
        printf("No Arguement Options\n");
        break;
      case 'n':
        printf("Arguement with Number\n");
        printf("Value: %d\n", atoi(optarg));
        break;
      case 's':
        printf("Arguement with String\n");
        str = optarg;
        printf("String: %s\n", str);
        break;
      case '?':
        printf("Unknown Arguement\n");
      default:
        printUsage();
        break;
    }
  }
 
  if (optind > argc) {
    printf("Expected Arguement After Options\n");
  }

  for (; optind < argc; optind++)
    printf("Remaining Arguement: %s\n", argv[optind]);

  return 0;
}
