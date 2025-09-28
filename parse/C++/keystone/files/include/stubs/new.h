
#ifndef _STL_NEW_
#define _STL_NEW_

#include <cstddef>

namespace std
{
   class bad_alloc
   {
   public:
      bad_alloc() throw();
      bad_alloc(const bad_alloc&) throw();
      bad_alloc& operator=(const bad_alloc&) throw();
      virtual ~bad_alloc() throw();
      virtual const char* what() const throw();
   };
   struct nothrow_t { };
   extern const nothrow_t nothrow;
   typedef void (*new_handler)();
   new_handler set_new_handler(new_handler) throw();

}  // end namespace std

void* operator new(std::size_t) throw(std::bad_alloc);
void* operator new(std::size_t, const std::nothrow_t&) throw();
void operator delete(void*) throw();
void operator delete(void*, const std::nothrow_t&) throw();

void* operator new[](std::size_t) throw(std::bad_alloc);
void* operator new[](std::size_t, const std::nothrow_t&) throw();
void operator delete[](void*) throw();
void operator delete[](void*, const std::nothrow_t&) throw();

void* operator new(std::size_t, void*) throw();
void* operator new[](std::size_t, void*) throw();
void operator delete(void*, void*) throw();
void operator delete[](void*, void*) throw();

#endif
