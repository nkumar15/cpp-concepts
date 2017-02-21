#ifndef RESOURCE_H
#define RESOURCE_H

#include <functional>
#include <string>


using Handler = std::function<void(void)>;

enum class RequestMethod {
  GET,
  PUT,
  POST,
  DELETE
};

class Resource {
  
  public:
    Resource(const std::string& path, RequestMethod method, const Handler& callback)
    : m_path{path}, m_method{method}, m_callback{callback} { } 

    void SetMethodHandler(const RequestMethod method, const Handler& callback);
    Handler GetMethodHandler();
   
    void SetPath(const std::string& path);
    std::string GetPath();

    Resource(const Resource& other) = delete;
    Resource& operator=(const Resource& rhs) = delete;

  private:
    std::string m_path;
    RequestMethod m_method;
    Handler m_callback;
};

#endif
