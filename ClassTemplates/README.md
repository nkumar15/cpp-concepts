# Class Templates

## Member functions
- Code is instantiated for only those member functions that are called. For class templates member functions are instantiated only
when they are used.
- If a class template has static members, these are instantiated for each type.
- `MyStack<int>`,`MyStack<float>`, `MyStack<int*>`, `MyStack<MyStack<int>>` are all valid types.

## Specialization of class templates
- You can specialize a class template for certain template arguments. Similar to the overloading of function templates. 
- It helps to optimize the implementation of certain types.
- Specializing a class template requires all member functions to specialize.
- But reverse is not true, specializing a single member function restrict specialization of class.
- To specialize a class syntax is below
- `template<>`
- `class MyStack<std::string>{...};`
- To specialize a member function syntax is below
- `void MyStack<std::string>::push(std::string & elem){....}`

## Partial Specialization of class templates
- You can specify special implementation for particular circumstances but some template parameter must still be defined. For eg:
- `template<typename T1,typename T2>`
- `class MyClass {....};`
- Following partial specialization are possible
-- Both parameters are same type
--- `template<typename T>`
--- `class MyClass<T,T> {....};`
-- second type is int
--- `template<typename T>`
--- `class MyClass<T,int> {....};`
-- both templates are pointer type
--- `template<typename T1,typename T2>`
--- `class MyClass<T1*,T2*> {....};`
- Following examples shows which template is called
-- `MyClass<int,float> m1;`     uses MyClass<T1,T2> 
-- `MyClass<int,int> m2;`       uses MyClass<T,T> 
-- `MyClass<float,int> m2;`     uses MyClass<T,int> 
-- `MyClass<float*,int*> m2;`   uses MyClass<T1*,T2*> 
- If  more than one partial specialization matches equally well, the declaration is ambigous.
-- Here `MyClass<int,int> m` will cause **error** coz it matches `MyClass<T,T>` and `MyClass<T,int>`
