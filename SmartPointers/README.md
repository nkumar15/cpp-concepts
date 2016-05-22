#Smart Pointers Concepts

##Types
-auto_ptr
-unique_ptr
-shared_ptr
-weak_ptr

## Problem with auto_ptr
- Transfer of ownership silently. Introduces potential bugs in code base.
- Cannot have a container of auto_ptr, becuase of no copy semantics.

## What unique_ptr solve
- Do not transfer ownership of underlying object implicitly.
- If ownership transfer needed, use std::move, that is move semantic.
- Can be used in containers.
