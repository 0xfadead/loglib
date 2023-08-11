# LogLib

## About
A basic, single-file and lightweight logging-library with a very creative name.

### Examples

#### Verbosity level
```c
#define SHOW_COLOR // enables ansi codes for color
#define SHOW_TIMESTAMP // enables functionality for displaying a timestamp
#include "llib.h"
#include <string.h>

int main(int ac, char **av) {
  ll_verbosity = LL_LOG_NORMAL;
  // check for arguments
  if (ac < 2) {
    log_warning("No arguments specified.");
  }

  // check for "verbose" option
  for (int i = 0; i < ac; i++) {
    if (!strcmp(av[i], "-v") || !strcmp(av[i], "--verbose")) {
      ll_verbosity = LL_LOG_ALL;
    }
  }

  // print every argument
  for (int i = 0; i < ac; i++) {
    log_info("Argument %i: `%s`", i, av[i]);
    // log_soft_info() only prints when ll_verbose is set to one
    log_soft_info("\tLength: %lu", strlen(av[i]));
  }

  return 0;
}
```

```
$ gcc example1.c -o example1 -Wall -Wextra -Werror
$ ./example1 -v --test
[i]  [20:57:27.497] main.c:20::main(): Argument 0: `./a.out`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 7
[i]  [20:57:27.497] main.c:20::main(): Argument 1: `-v`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 2
[i]  [20:57:27.497] main.c:20::main(): Argument 2: `--test`
[ii] [20:57:27.497] main.c:22::main(): 	Length: 6
```

#### Progress bar

```c
#define PROGRESS_BAR_IMPLEMENTATION
#include "llib.h"

#ifdef _WIN32
#include <windows.h> // F you windoors
#else
#include <unistd.h>
#endif

void _sleep(unsigned long ms) {
#ifdef _WIN32
  Sleep(ms);
#else
  usleep(ms * 1000);
#endif
}

int main(void) {
  llprogress_bar pbar = (llprogress_bar){
      .current = 0,    // current step
      .max_size = 50, // the maximum step
      .length = 50,   // length of progress bar in chars

      .progress_style = "\e[1;32m",
      .progress_char = 0, // will default to '-'
      .trans_style = "\e[1;33m",
      .trans_char = '>',
      .empty_style = "\e[0;31m",
      .empty_char = 0, // will default to ' '

      .start_text = "Test text",
      .end_text = "Test text (new and improved BUY NOW for only $39.99)",

      .start_char = 0, // defaults to '['
      .end_char = 0,   // defaults to ']'
  };

  while (pbar.out_current_percent < 100.0) {
    update_progress_bar(
        &pbar, 0);     // the second argument just tells it to print a newline
    _sleep(50);        // sleep for 50 ms
    pbar.current++;    // update the current step
  }

  update_progress_bar(&pbar, 1); // last step to print the newline
}

```

```
$ gcc example2.c -o example2
$ ./example2
Test text [------------------------------------------------>] Test text (new and improved)
```
