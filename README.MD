# LogLib
A basic and lightweight logging-library with a very creative name.

## Examples
```
#define SHOW_TIMESTAMP // enables functionality for displaying a timestamp
#include "llib.h"
#include <string.h>

int main(int ac, char **av) {
  // check for arguments
  if (ac < 2) {
    log_warning("No arguments specified.");
  }

  // check for "verbose" option
  for (int i = 0; i < ac; i++) {
    if (!strcmp(av[i], "-v") || !strcmp(av[i], "--verbose")) {
      ll_verbose = 1;
    }
  }

  // print every argument
  for (int i = 0; i < ac; i++) {
    log_info("Argument %i: `%s`", i, av[i]);
    // log_verbose_info() only prints when ll_verbose is set to one
    log_verbose_info("\tLength: %lu", strlen(av[i]));
  }

  return 0;
}
```

### Output with input `./a.out -v --test`
```
[i]  [20:57:27.497] main.c:20::main(): Argument 0: `./a.out`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 7
[i]  [20:57:27.497] main.c:20::main(): Argument 1: `-v`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 2
[i]  [20:57:27.497] main.c:20::main(): Argument 2: `--test`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 6
```