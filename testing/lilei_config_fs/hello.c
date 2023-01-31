#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

//extern size_t up_check_stack(void);

int main(int argc, FAR char *argv[])
{
  syslog(LOG_INFO,"begin malloc\n");
  char *p = (char *)malloc(5);
  
  p[1] = '1';
  syslog(LOG_INFO,"p1 is %c p is %p\n",p[1],p);
  
  free(p);
  return 0;
}

