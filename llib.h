#ifndef LLIB_H
#define LLIB_H

#include <stdio.h>

#ifndef VERBOSE_INFO_PREFIX
#define VERBOSE_INFO_PREFIX "[ii] "
#endif
#ifndef INFO_PREFIX
#define INFO_PREFIX "[i]  "
#endif
#ifndef IMPORTANT_INFO_PREFIX
#define IMPORTANT_INFO_PREFIX "[I]  "
#endif

#ifndef VERBOSE_PROGRESS_PREFIX
#define VERBOSE_PROGRESS_PREFIX "[**] "
#endif
#ifndef PROGRESS_PREFIX
#define PROGRESS_PREFIX "[*]  "
#endif

#ifndef VERBOSE_WARNING_PREFIX
#define VERBOSE_WARNING_PREFIX "[ww] "
#endif
#ifndef WARNING_PREFIX
#define WARNING_PREFIX "[w]  "
#endif
#ifndef IMPORTANT_WARNING_PREFIX
#define IMPORTANT_WARNING_PREFIX "[W]  "
#endif

#ifndef VERBOSE_ERROR_PREFIX
#define VERBOSE_ERROR_PREFIX
#endif
#ifndef ERROR_PREFIX
#define ERROR_PREFIX "[e]  "
#endif
#ifndef IMPORTANT_ERROR_PREFIX
#define IMPORTANT_ERROR_PREFIX "[E]  "
#endif
#ifndef FATAL_PREFIX
#define FATAL_PREFIX "[F]  "
#endif

static int ll_verbose = 0;

#ifdef SHOW_TIMESTAMP

static char *llib_timestamp(void);

#define log_verbose_info(FORMAT, ...)                                          \
  if (ll_verbose)                                                              \
  printf(VERBOSE_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",                 \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_info(FORMAT, ...)                                                  \
  printf(INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),       \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_important_info(FORMAT, ...)                                        \
  printf(IMPORTANT_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",               \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_progress(FORMAT, ...)                                      \
  if (ll_verbose)                                                              \
  printf(VERBOSE_PRODEBUG_PROGRESS_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",    \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_progress(FORMAT, ...)                                              \
  printf(PROGRESS_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),   \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_warning(FORMAT, ...)                                       \
  if (ll_verbose)                                                              \
  printf(VERBOSE_WARNING_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",              \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_warning(FORMAT, ...)                                               \
  printf(WARNING_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),    \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_important_warning(FORMAT, ...)                                     \
  printf(IMPORTANT_INFO_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",               \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_error(FORMAT, ...)                                         \
  if (ll_verbose)                                                              \
  printf(VERBOSE_ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",                \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_error(FORMAT, ...)                                                 \
  printf(ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),      \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_important_error(FORMAT, ...)                                       \
  printf(IMPORTANT_ERROR_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n",              \
         llib_timestamp(), __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_fatal(FORMAT, ...)                                                 \
  printf(FATAL_PREFIX "[%s] %s:%i::%s(): " FORMAT "\n", llib_timestamp(),      \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define log_verbose_info(FORMAT, ...)                                          \
  if (ll_verbose)                                                              \
  printf(VERBOSE_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,  \
         __FUNCTION__, ##__VA_ARGS__)
#define log_info(FORMAT, ...)                                                  \
  printf(INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,          \
         __FUNCTION__, ##__VA_ARGS__)
#define log_important_info(FORMAT, ...)                                        \
  printf(IMPORTANT_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__,          \
         __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_progress(FORMAT, ...)                                      \
  if (ll_verbose)                                                              \
  printf(VERBOSE_PRODEBUG_PROGRESS_PREFIX "%s:%i::%s(): " FORMAT "\n",         \
         __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_progress(FORMAT, ...)                                              \
  printf(PROGRESS_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,      \
         __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_warning(FORMAT, ...)                                       \
  if (ll_verbose)                                                              \
  printf(VERBOSE_WARNING_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__,         \
         __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_warning(FORMAT, ...)                                               \
  printf(WARNING_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,       \
         __FUNCTION__, ##__VA_ARGS__)
#define log_important_warning(FORMAT, ...)                                     \
  printf(IMPORTANT_INFO_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__,          \
         __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define log_verbose_error(FORMAT, ...)                                         \
  if (ll_verbose)                                                              \
  printf(VERBOSE_ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__, \
         __FUNCTION__, ##__VA_ARGS__)
#define log_error(FORMAT, ...)                                                 \
  printf(ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,         \
         __FUNCTION__, ##__VA_ARGS__)
#define log_important_error(FORMAT, ...)                                       \
  printf(IMPORTANT_ERROR_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__,         \
         __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define log_fatal(FORMAT, ...)                                                 \
  printf(FATAL_PREFIX "%s:%i::%s(): " FORMAT "\n", __FILE__, __LINE__,         \
         __FUNCTION__, ##__VA_ARGS__)
#endif // SHOW_TIMESTAMP
#endif // LLIB_H

// #define SHOW_TIMESTAMP

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
#endif
