#include <stdio.h>

#include "acetest.h"

int getVersion()
{
  return 2;
}

void printVersion()
{
  printf("=========================\n");
  printf("version: %d\n", getVersion());
  printf("=========================\n");
}