
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <git2.h>

#define GIT_INSTALLED 0

class Book
{
public:
  Book(std::string path_name);
  void download(std::string remote_name);
  void download_progress(std::string remote_name);
  void load_config();

private:
  #if GIT_INSTALLED
  static int fetch_progress(const git_transfer_progress *stats, void *payload);

  static void checkout_progress(const char *path,
                                size_t cur,
                                size_t tot,
                                void *payload);
  typedef struct
  {
    int data;
  } progress_data;

  #endif

  std::string m_local_path;

  std::string m_config_filename;
};

#endif
