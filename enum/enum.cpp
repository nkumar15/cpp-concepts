#include <iostream>

using namespace std;

struct Request {

  enum class Method {
    GET,
    POST,
    PUT,
    DELETE
  };

  Method method;
};


int main() {

  Request request;
  request.method = Request::Method::GET;

  switch (request.method) {
   case Request::Method::GET:
     std::cout << "GET" << std::endl;
     break;
   case Request::Method::PUT:
     std::cout << "PUT" << std::endl;
     break;
   case Request::Method::POST:
     std::cout << "POST" << std::endl;
     break;
   case Request::Method::DELETE:
     std::cout << "DELETE" << std::endl;
     break;
   default:
     std::cout << "Invalid method" << std::endl;
     break;
  }

}
