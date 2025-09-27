#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
int len = strlen(argv[1]);

for (int i = len-1; i >= 0; i--)
{
switch(argv[1][i]){
  case '0':
      printf("00");
      break;
  case '1':
      printf("11");
      break;
  case 'F':
  case 'f':
      printf("01");
      break;
  default:
      printf("none");
  }

}
return 0;
}
