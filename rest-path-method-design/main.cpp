#include "resource.hpp"
#include <memory>
#include <iostream>
#include <map>

void LoginMethodHandler() {
  std::cout << "Code here to handle a login request." << std::endl;
}

int main() {
  using ResourceSharedPtr = std::shared_ptr<Resource>;

  ResourceSharedPtr resource_ptr = std::make_shared<Resource>();
  resource_ptr->SetPath("/login");
  resource_ptr->SetMethodHandler(RequestMethod::GET, LoginMethodHandler);

  resource_ptr->GetMethodHandler()();

  auto path_map = std::make_pair(resource_ptr->GetPath(),resource_ptr);
  
  std::multimap<std::string, ResourceSharedPtr> my_map;
  my_map.insert(path_map);
 
    
  return 0;

  
}
