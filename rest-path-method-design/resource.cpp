#include "resource.hpp"

void Resource::SetPath(const std::string& path) {
  m_path = path;
}


std::string Resource :: GetPath() {
  return m_path;
}

void Resource :: SetMethodHandler(RequestMethod method, const Handler& callback) {
  m_method = method;
  m_callback = callback;
}

Handler Resource :: GetMethodHandler() {
  return m_callback;
}



