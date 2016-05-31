
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <git2.h>

class Book
{
public:
  Book(std::string path_name);
  void download(std::string remote_name);
  void download_progress(std::string remote_name);
private:

  static int fetch_progress(const git_transfer_progress *stats, void *payload);

  static void checkout_progress(const char *path,
                                size_t cur,
                                size_t tot,
                                void *payload);
  

  typedef struct
  {
    int data;
  } progress_data;

  std::string m_local_path;
};

#endif
