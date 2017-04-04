#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define debug(fmt, args...) \
  printf(". " fmt "\n", ##args);

#define debug_danger(fmt, args...) \
  debug("\033[32;1m" fmt "\033[0m\n", ##args)


typedef void* PVOID;
typedef char* PCHAR;

int sayHello() {
  
  debug("Goodbye!");
  
  return 3;
}

int main(void) {
   
  debug("Start...")
  
  const PCHAR lib_path = "/home/mcutter/git/dl_samples/libsample.so";
  const PCHAR fn_name = "sayHello";  
  
  debug("dlopen %s", lib_path)
  PVOID lib_handle = dlopen(lib_path, RTLD_LAZY | RTLD_DEEPBIND);
  
  if(lib_handle != NULL) {
    
    debug("dlsym: %s", fn_name);
    int (*fn)(void) = dlsym(lib_handle, fn_name); 
    
    if(fn != NULL) {
      debug("Running fn")
      int status = 0;
      status = fn();
      debug("returned %d", status);
      status = sayHello();
      debug("returned %d", status);
    }

    debug("dlclose");
    dlclose(lib_handle);    
  } else {
     debug_danger("Failed to open %s", lib_path);
  }
  return 0;
}
