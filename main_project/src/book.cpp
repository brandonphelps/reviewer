
#include "book.h"

#if GIT_INSTALLED
  #include <git2.h>
#endif

#include <iostream>
#include <string>
#include <fstream>

Book::Book(std::string path_name) : m_local_path(path_name)
{
  m_config_filename = m_local_path + "/config.txt";
}

void Book::download(std::string remote_name)
{
  #if GIT_INSTALLED
    git_repository *repo = NULL;

    int error = git_clone(&repo, remote_name.c_str(), m_local_path.c_str(), NULL);

    if(error)
    {
      std::cout << "Clone Error: " << error << std::endl;    
    }
  
    git_repository_free(repo);
  #endif
}

  
void Book::download_progress(std::string remote_name)
{
  #if GIT_INSTALLED 
    progress_data d = {0};

    git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
    
    clone_opts.checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
    clone_opts.checkout_opts.progress_cb = checkout_progress;
    clone_opts.checkout_opts.progress_payload = &d;
    // clone_opts.checkout_opts = checkout_opts; ?
    clone_opts.fetch_opts.callbacks.transfer_progress = fetch_progress;
    clone_opts.fetch_opts.callbacks.payload = &d;
    
    git_repository *repo = NULL;
    
    int error = git_clone(&repo, remote_name.c_str(), m_local_path.c_str(), &clone_opts);
    
    git_repository_free(repo);
  #endif
}

void Book::load_config()
{
  std::ifstream config_file(m_config_filename.c_str());

  std::string line;

  if(config_file.is_open())
  {
    while(getline(config_file, line))
    {
      std::cout << line << std::endl;
    }      
  }
  else
  {
    std::cout << "Unable to read: " << m_config_filename << std::endl;
  }
  config_file.close();
}

#if GIT_INSTALLED
int Book::fetch_progress(const git_transfer_progress *stats, void *payload)
{
  progress_data *pd = (progress_data*)payload;
  /* do something with network transfer progress */
  std::cout << "Fetch progress" << std::endl;
  return 0;
}
#endif


#if GIT_INSTALLED
void Book::checkout_progress(const char *path,
                             size_t cur,
                             size_t tot,
                             void *payload)
{
  progress_data *pd = (progress_data*)payload;
  //std::cout << "Checkout progress " << pd->data << std::endl;
  //std::cout << "Current: " << cur << std::endl;
  //std::cout << "Total: " << tot << std::endl;
  std::cout << "Current checkout: " << cur / float(tot) << std::endl;
  /* do something with checkout progress */
}
#endif
