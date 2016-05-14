#Function Templates

## Left over task
> Argument deduction to understand.

##General concepts

### Syntax
`template<typename T>`
`void sum(T a, T b)`
- T is called template parameter
- a and b are called call parameters
- `sum<int>(1,2)` is way to call a template function

### Default argument
- Prior to C++ 11, default argument were not valid in C++.
- But C++ 11 supports default arguments for templates.

### Argument Deduction
- What happens when you call a template function like a normal function. For example `sum(1,2)`, how does compiler knows the template parameter and call parameter types. Here comes the concept of function template argument deduction.

### Overloaded function resolution
- Like ordinary functions, function templates can be overloaded. That is, you can have different function definitions with
the same function name so that when that name is used in a function call, a C++ compiler must decide which one of
the various candidates to call.
- (http://stackoverflow.com/questions/22411482/c-template-functions-overload-resolution)

### Template Specialization & Partial Specialization
- (http://www.cprogramming.com/tutorial/template_specialization.html)



