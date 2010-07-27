
#include <../pthread.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>

static pthread_mutex_t getpw_mutex = PTHREAD_MUTEX_INITIALIZER;

static int
convert (struct passwd *ret, struct passwd *result,
       char *buf, int buflen)
{
  int len;

  if (!buf) return -1;

  *result = *ret;
/*  user name */
  result->pw_name = (char *) buf;
  len = strlen (ret->pw_name) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_name, ret->pw_name);

/*  user password */
  result->pw_passwd = (char *) buf;
  len = strlen (ret->pw_passwd) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_passwd, ret->pw_passwd);

/*  real name */
  result->pw_gecos = (char *) buf;
  len = strlen (ret->pw_gecos) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_gecos, ret->pw_gecos);

/*  home directory */
  result->pw_dir = (char *) buf;
  len = strlen (ret->pw_dir) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_dir, ret->pw_dir);

/* shell program */
  result->pw_shell = (char *) buf;
  len = strlen (ret->pw_shell) + 1;
  if (len > buflen) return -1;
  buflen -= len;
  buf += len;
  strcpy (result->pw_shell, ret->pw_shell);

  return 0;
}

int
getpwnam_r (const char *name, 
       struct passwd *result, char *buffer, size_t buflen)
{
  struct passwd *ret;

  pthread_mutex_lock (&getpw_mutex);

  ret = getpwnam (name);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getpw_mutex);
  return 0;
}

int
getpwuid_r (uid_t uid, 
       struct passwd *result, char *buffer, size_t buflen)
{
  struct passwd *ret;

  pthread_mutex_lock (&getpw_mutex);

  ret = getpwuid(uid);
  if (!ret ||
       convert (ret, result, buffer, buflen) != 0)
  {
    result = NULL;
  }

  pthread_mutex_unlock (&getpw_mutex);
  return 0;
}
