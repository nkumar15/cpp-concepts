include "resource.hpp"
#include <memory>
#include <iostream>
#include <map>

using ResourceSharedPtr = std::shared_ptr<Resource>;
using ResourceMap = std::multimap<std::string, ResourceSharedPtr>;

void Login() {
  std::cout << "Code here to handle a login request." << std::endl;
}

void Logout() {
  std::cout << "Code here to handle a logoutrequest." << std::endl;
}


void CallHandler(const std::string &path, ResourceMap &map) {

  auto range = map.equal_range(path);

  if (range.first == range.second) return;

  
  for(auto r = range.first; r != range.second; r++) {
    ResourceSharedPtr& ptr = r->second;
    std::cout << r->first << std::endl;
    ptr->GetMethodHandler()();
  }
}

int main() {

  const std::string login = "/login";
  const std::string logout = "/logout";


  ResourceSharedPtr login_res_ptr = std::make_shared<Resource>();
  login_res_ptr->SetPath(login);
  login_res_ptr->SetMethodHandler(RequestMethod::GET, Login);
  auto login_map = std::make_pair(login,login_res_ptr);
  
  ResourceSharedPtr logout_res_ptr = std::make_shared<Resource>();
  logout_res_ptr->SetPath(logout);
  logout_res_ptr->SetMethodHandler(RequestMethod::GET, Logout);
  auto logout_map = std::make_pair(logout,logout_res_ptr);


  ResourceMap my_map;
  my_map.insert(login_map);
  my_map.insert(logout_map);

  int input;
  std::cout << "Enter 1 for login and 2 for logout: ";
  std::cin >> input;

  std::string search_path;
  if (input == 1) {
    search_path = login;
  }
  else {
    search_path = logout;
  }

  CallHandler(search_path, my_map);  
    
  return 0;

  
}
