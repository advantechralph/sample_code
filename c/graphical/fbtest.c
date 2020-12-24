#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <stdlib.h>

struct fb_var_screeninfo vinfo;

int
main(int argc, char *argv[])
{
 int fbfd, fbsize, i;
 int red, green, blue;
 unsigned char *fbbuf;

 if (argc != 4) {
  printf("usage: use-fb red green blue/n");
  exit(0);
 }
 red = atoi(argv[1]);
 green = atoi(argv[2]);
 blue = atoi(argv[3]);
 
 /* Open video memory */
 if ((fbfd = open("/dev/fb0", O_RDWR)) < 0) {
  exit(1);
 } 
 /* Get variable display parameters */
 if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
  printf("Bad vscreeninfo ioctl/n");
  exit(2);
 }
 /* Size of frame buffer */
 fbsize = vinfo.xres*vinfo.yres*(vinfo.bits_per_pixel/8);
 /* Map video memory */
 if ((fbbuf = mmap(0, fbsize, PROT_READ | PROT_WRITE,
  MAP_SHARED, fbfd, 0)) == (void *) -1) {
  exit(3);
 }
 /* Clear the screen */ 
 for (i = 0; i < fbsize; i++) {
  *(fbbuf + i++) = red;
  *(fbbuf + i++) = green;
  *(fbbuf + i) = blue;
 }
  
 printf("clear screen with rgb:%s %s %s/n", argv[1], argv[2], argv[3]);
 munmap(fbbuf, fbsize);
 close(fbfd);
}
