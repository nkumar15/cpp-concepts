# General Concepts

## Member functions
- Code is instantiated for only those member functions that are called. For class templates member functions are instantiated only
when they are used.
- If a class template has static members, these are instantiated for each type.
- `MyStack<int>`,`MyStack<float>`, `MyStack<int*>`, `MyStack<MyStack<int>>` are all valid types.

## Specialization of class templates
