#ifndef __EXCEPRIONS__
#define __EXCEPTIONS__

#include <exception>

class SDLInitException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "SDL could not initialize!";
  }
};

class SDLSetHintException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "SDL could not set hint!";
  }
};

class SDLCreateWindowException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "SDL could not create window!";
  }
};

class SDLCreateRendererException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "SDL could not create renderer!";
  }
};

class SDLIMGInitException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "SDL_Image could not initialize!";
  }
};

class SDLIMGLoadException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "Unable to load image!";
  }
};

class SDLCreateTexturException : public std::exception
{
  virtual const char *what() const throw()
  {
    return "Unable to create texture!";
  }
};

#endif