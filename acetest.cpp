#include <stdio.h>

#include "acetest.h"

int getVersion()
{
  return 1;
}

void printVersion()
{
  printf("=========================\n");
  printf("version: %d\n", getVersion());
  printf("=========================\n");
}