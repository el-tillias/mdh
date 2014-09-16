#include <stdio.h>
#include <strings.h>


int main(void) {
int k = 10;

printf("address of k is %p\n", &k);
printf("value of k is %d\n", k);

int *ptr = &k;

printf("value in the address ptr points to %d\n", *ptr);
printf("address of ptr(points to &k: %p\n", ptr);

return 0;

}
