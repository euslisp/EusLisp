#include <sys/time.h>
#include <sys/resource.h>

main(){
  getpriority(0,0);
  setpriority(0,0,0);
}
