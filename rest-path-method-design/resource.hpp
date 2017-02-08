#include <functional>
#include <string>


typedef std::function<void(void)> Handler;

enum class RequestMethod {
  GET,
  PUT,
  POST,
  DELETE
};

class Resource {
  
  public:
    Resource() {} 
    void SetMethodHandler(const RequestMethod method, const Handler& callback);
    Handler GetMethodHandler();
   
    void SetPath(const std::string& path);
    std::string& GetPath();

 
   
  private:
    Resource(const Resource& other) = delete;
    Resource& operator=(Resource& rhs) = delete;

    std::string m_path;
    RequestMethod m_method;
    Handler m_callback;
};


