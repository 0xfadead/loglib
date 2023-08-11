#ifndef LLIB_H
#define LLIB_H

#include <stdio.h>

// Ansi escape sequences for logging with color
#ifdef SHOW_COLOR
#ifndef INFO_COLOR
#define INFO_COLOR "\e[1;32m" // GREEN
#endif
#ifndef PROGRESS_COLOR
#define PROGRESS_COLOR "\e[1;36m" // CYAN
#endif
#ifndef WARNING_COLOR
#define WARNING_COLOR "\e[1;33m" // YELLOW
#endif
#ifndef ERROR_COLOR
#define ERROR_COLOR "\e[1;31m" // RED
#endif
#ifndef FATAL_COLOR
#define FATAL_COLOR "\e[1;35m" // PURPLE
#endif

#ifndef ANSI_RESET
#define ANSI_RESET "\e[0;0m"
#endif

#else
#define INFO_COLOR ""
#define PROGRESS_COLOR ""
#define WARNING_COLOR ""
#define ERROR_COLOR ""
#define FATAL_COLOR ""
#define ANSI_RESET ""
#endif

#ifndef SOFT_INFO_PREFIX
#define SOFT_INFO_PREFIX "[" INFO_COLOR "ii" ANSI_RESET "] "
#endif
#ifndef INFO_PREFIX
#define INFO_PREFIX "[" INFO_COLOR "i" ANSI_RESET "]  "
#endif
#ifndef HARD_INFO_PREFIX
#define HARD_INFO_PREFIX "[" INFO_COLOR "I]" ANSI_RESET "  "
#endif

#ifndef SOFT_PROGRESS_PREFIX
#define SOFT_PROGRESS_PREFIX "[" PROGRESS_COLOR "**" ANSI_RESET "] "
#endif
#ifndef PROGRESS_PREFIX
#define PROGRESS_PREFIX "[" PROGRESS_COLOR "*" ANSI_RESET "]  "
#endif

#ifndef SOFT_WARNING_PREFIX
#define SOFT_WARNING_PREFIX "[" WARNING_COLOR "ww" ANSI_RESET "] "
#endif
#ifndef WARNING_PREFIX
#define WARNING_PREFIX "[" WARNING_COLOR "w" ANSI_RESET "]  "
#endif
#ifndef HARD_WARNING_PREFIX
#define HARD_WARNING_PREFIX "[" WARNING_COLOR "W" ANSI_RESET "]  "
#endif

#ifndef SOFT_ERROR_PREFIX
#define SOFT_ERROR_PREFIX "[" ERROR_COLOR "ee" ANSI_RESET "] "
#endif
#ifndef ERROR_PREFIX
#define ERROR_PREFIX "[" ERROR_COLOR "e" ANSI_RESET "]  "
#endif
#ifndef HARD_ERROR_PREFIX
#define HARD_ERROR_PREFIX "[" ERROR_COLOR "E" ANSI_RESET "]  "
#endif
#ifndef FATAL_PREFIX
#define FATAL_PREFIX "[" FATAL_COLOR "F" ANSI_RESET "]  "
#endif

enum {
  LL_LOG_HARD = 0,
  LL_LOG_NORMAL = 1,
  LL_LOG_ALL = 2,
};

static int ll_verbosity = LL_LOG_NORMAL;

#ifdef SHOW_TIMESTAMP

static char *llib_timestamp(void);

#define log_soft_info(FORMAT, ...)                                             \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),  \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_info(FORMAT, ...)                                                  \
  if (ll_verbosity)                                                            \
  printf(INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),       \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_hard_info(FORMAT, ...)                                             \
  printf(HARD_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),  \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_soft_progress(FORMAT, ...)                                         \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_PROGRESS_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",                \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_progress(FORMAT, ...)                                              \
  if (ll_verbosity)                                                            \
  printf(PROGRESS_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),   \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_soft_warning(FORMAT, ...)                                          \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_WARNING_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",                 \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_warning(FORMAT, ...)                                               \
  if (ll_verbosity)                                                            \
  printf(WARNING_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),    \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_hard_warning(FORMAT, ...)                                          \
  printf(HARD_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),  \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_soft_error(FORMAT, ...)                                            \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(), \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_error(FORMAT, ...)                                                 \
  if (ll_verbosity)                                                            \
  printf(ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),      \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_hard_error(FORMAT, ...)                                            \
  printf(HARD_ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(), \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_fatal(FORMAT, ...)                                                 \
  printf(FATAL_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),      \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define log_soft_info(FORMAT, ...)                                             \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,     \
         __FUNCTION__, ##__VA_ARGS__)
#define log_info(FORMAT, ...)                                                  \
  if (ll_verbosity)                                                            \
  printf(INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,          \
         __FUNCTION__, ##__VA_ARGS__)
#define log_hard_info(FORMAT, ...)                                             \
  printf(HARD_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,     \
         __FUNCTION__, ##__VA_ARGS__)

#define log_soft_progress(FORMAT, ...)                                         \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_PROGRESS_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__, \
         __FUNCTION__, ##__VA_ARGS__)
#define log_progress(FORMAT, ...)                                              \
  if (ll_verbosity)                                                            \
  printf(PROGRESS_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,      \
         __FUNCTION__, ##__VA_ARGS__)

#define log_soft_warning(FORMAT, ...)                                          \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_WARNING_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,  \
         __FUNCTION__, ##__VA_ARGS__)
#define log_warning(FORMAT, ...)                                               \
  if (ll_verbosity)                                                            \
  printf(WARNING_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,       \
         __FUNCTION__, ##__VA_ARGS__)
#define log_hard_warning(FORMAT, ...)                                          \
  printf(HARD_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,     \
         __FUNCTION__, ##__VA_ARGS__)

#define log_soft_error(FORMAT, ...)                                            \
  if (ll_verbosity > 1)                                                        \
  printf(SOFT_ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,    \
         __FUNCTION__, ##__VA_ARGS__)
#define log_error(FORMAT, ...)                                                 \
  if (ll_verbosity)                                                            \
  printf(ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,         \
         __FUNCTION__, ##__VA_ARGS__)
#define log_hard_error(FORMAT, ...)                                            \
  printf(HARD_ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,    \
         __FUNCTION__, ##__VA_ARGS__)
#define log_fatal(FORMAT, ...)                                                 \
  printf(FATAL_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,         \
         __FUNCTION__, ##__VA_ARGS__)
#endif // SHOW_TIMESTAMP

#ifdef PROGRESS_BAR_IMPLEMENTATION

typedef struct {
  unsigned short length;
  unsigned long current;  // current status
  unsigned long max_size; // maximum status
  char start_char;        // character before the actual progress display
  char *progress_style;   // string for ANSI sequence to change color and/or
                          // formatting of the progress-chars
  char progress_char;     // character to symbolise progress
  char *trans_style;      // same as progress_style
  char trans_char;   // character between the progress_char and empty_char (will
                     // be the same as the progress_char if set to zero)
  char *empty_style; // same as progress style
  char empty_char;   // character, which fills the empty space of progress
  char end_char;     // character after the actual progress display
  const char *start_text; // text before the progress display
  const char *end_text;   // text after the progress display
  char min_verbosity_level;
} llprogress_bar;

void update_progress_bar(llprogress_bar p, char last);

#endif // PROGRESS_BAR_IMPLEMENTATION

#ifdef SHOW_TIMESTAMP
#include <sys/time.h>
#include <time.h>

static char time_out_str[(41) * sizeof(char)];

static char *llib_timestamp(void) {
  struct timeval current_time;

  gettimeofday(&current_time, NULL);

  struct tm *time_fmt = localtime(&current_time.tv_sec);
  short ms = current_time.tv_usec / 1000 % 1000;

  sprintf(time_out_str, "%02i:%02i:%02i.%03i", time_fmt->tm_hour,
          time_fmt->tm_min, time_fmt->tm_sec, ms);

  return time_out_str;
}
#endif // SHOW_TIMESTAMP

#ifdef PROGRESS_BAR_IMPLEMENTATION
#include <stdio.h>

void update_progress_bar(llprogress_bar p, char last) {
  float progress = (float)p.current / p.max_size;
  if (progress > 1.0)
    progress = 1.0;

  if (p.progress_char == 0)
    p.progress_char = '#';
  if (p.trans_char == 0)
    p.trans_char = p.progress_char;
  if (p.empty_char == 0)
    p.empty_char = ' ';

  if (p.start_char == 0)
    p.start_char = '[';
  if (p.end_char == 0)
    p.end_char = ']';

#ifndef SHOW_COLOR
  p.progress_style = NULL;
  p.trans_style = NULL;
  p.progress_style = NULL;
#endif

  unsigned short progress_amount = (unsigned short)((p.length * progress));
  unsigned short empty_amount =
      (unsigned short)(p.length - (p.length * progress));

  if (!progress_amount && empty_amount)
    empty_amount--;
  if (progress_amount)
    progress_amount--;

  if (progress_amount + empty_amount + 1 < p.length) {
    empty_amount += p.length - progress_amount - 1 - empty_amount;
  }

  char progress_chars[(progress_amount + 1) * sizeof(char)];

  char empty_chars[(empty_amount + 1) * sizeof(char)];

  for (unsigned short i = 0; i < progress_amount; i++) {
    progress_chars[i] = p.progress_char;
  }

  progress_chars[progress_amount] = '\0';
  empty_chars[empty_amount] = '\0';

  for (unsigned short i = 0; i < empty_amount; i++) {
    empty_chars[i] = p.empty_char;
  }

  if (ll_verbosity >= p.min_verbosity_level) {
    printf("\r%s %c%s%s%s%c%s%s" ANSI_RESET "%c %s",
           (!p.start_text ? "" : p.start_text), p.start_char,
           (!p.progress_style ? "" : p.progress_style), progress_chars,
           (!p.trans_style ? "" : p.trans_style), p.trans_char,
           (!p.empty_style ? "" : p.empty_style), empty_chars, p.end_char,
           (!p.end_text ? "" : p.end_text));
    fflush(stdout);
  }

  if (last)
    puts("");
}
#endif // PROGRESS_BAR_IMPLEMENTATION

#endif // LLIB_H
