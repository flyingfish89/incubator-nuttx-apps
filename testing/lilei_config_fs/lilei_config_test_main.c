/****************************************************************************
 * apps/lilei_config_fs/lilei_config_test_main.c
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/mount.h>
#include <sys/ioctl.h>
#include <sys/statfs.h>
#include <nuttx/i2c/i2c_master.h>

#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <nuttx/crc8.h>
#include <debug.h>
#include <assert.h>
#include <stdio.h>
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/


int main(int argc, char *argv[])
{
  int ret;
  int countnum;
  struct i2c_msg_s msg;
  
  struct i2c_transfer_s msfer;
  uint8_t information;
  int fd;

  char *path="/dev/i2c0";
  msg.frequency = 10000;
  msg.addr      = 0b1101001;
  msg.flags     = 0x0001;
  msg.buffer    = &information;
  msg.length    = 1;

  msfer.msgv=&msg;
  msfer.msgc=1;

  fd=open(path,1);
  if(fd<0) 
  {
    printf("file open err %d\n",fd);
    return 0;
  }
  countnum=1;
  while(1)
  {   
      ret=ioctl(fd,_I2CIOC(0x0001),(unsigned long)((unsigned long)&msfer));
      if(ret<0)
      {
         printf("ioctl err! the %d number,ret:%d\n",countnum,ret);
         break;
      }
      else printf("ioctl successed %d\n",countnum);
      sleep(1);
      countnum++;
  }
  return 0;   
}
 



