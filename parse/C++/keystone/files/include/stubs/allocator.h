#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

#include <cstddef>

namespace std
{
   template<class T> class allocator
   {
   public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef T* pointer;
      typedef const T* const_pointer;
      typedef T& reference;
      typedef const T& const_reference;
      typedef T value_type;
      template<class U> struct rebind { typedef allocator<U> other; };

      allocator() throw();
      allocator( const allocator& ) throw();
      template<class U> allocator( const allocator<U>& ) throw();
      ~allocator() throw();

      pointer
      address(reference x) const;
      const_pointer
      address(const_reference x) const;

      pointer
      allocate( size_type, const void* hint = 0);
      void
      deallocate(pointer p, size_type n);
      size_type
      max_size() const throw();

      void
      construct(pointer p, const T& val);
      void
      destroy(pointer p);
   };
   
   template<> class allocator<void> {
   public:
      typedef void* pointer;
      typedef const void* const_pointer;
      typedef void value_type;
      template<class U> struct rebind { typedef allocator<U> other; };
   };

   template<class T, class U>
   bool
   operator==(const allocator<T>&, const allocator<U>&) throw();
   template<class T, class U>
   bool
   operator!=(const allocator<T>&, const allocator<U>&) throw();
   
}  // namespace std

#endif
