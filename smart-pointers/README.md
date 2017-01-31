#Smart Pointers Concepts

##Types
- auto_ptr
- unique_ptr
- shared_ptr
- weak_ptr

## Problem with auto_ptr
- Transfer of ownership silently. Introduces potential bugs in code base.
- Cannot have a container of auto_ptr, becuase of no copy semantics.

## What unique_ptr solves?
- Do not transfer ownership of underlying object implicitly.
- If ownership transfer needed, use std::move, that is move semantic.
- Can be used in containers.

## Shared pointer and weak pointer
- Used when multiple owners are requried to manage an object.
- use_count() function is useful for checking reference count.
- std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr
- weak pointer lock() and expired() method are useful in weak pointer.

## Backward compatibilty
- When legacy function expects raw pointer, use get() method on smart pointer to fetch raw pointer of underlying object.

