#ifndef _CHAR_TRAITS_
#define _CHAR_TRAITS_

//#include <fpos.h>
//#include <iosfwd>
#include <ios_types.h>
#include <mbstate.h>
#include <cstddef>

#ifndef HAVE_FPOS
#define HAVE_FPOS
namespace std
{
   template <class> class fpos {};
        typedef long _STATE;
   typedef fpos <_STATE> streampos;
   typedef fpos <_STATE> wstreampos;
   //typedef fpos <char_traits<char>::state_type>    streampos;
   //typedef fpos <char_traits<wchar_t>::state_type> wstreampos;
}   

#endif


namespace std {
   template<class charT> struct char_traits;
} // end namespace std

#include <iosfwd>

namespace std {
   template<>
   struct char_traits<char> {
      typedef char char_type;
      typedef int int_type;
      typedef streamoff off_type;
      typedef streampos pos_type;
      typedef mbstate_t state_type;

      static void assign(char_type& c1, const char_type& c2);
      static bool eq(const char_type& c1, const char_type& c2);
      static bool lt(const char_type& c1, const char_type& c2);
      static int compare( const char_type* sq, const char_type* s2,
                          size_t n );
      static size_t length( const char_type* s);
      static const char_type* find( const char_type* s, size_t n,
                                    const char_type& a);
      static char_type* move(char_type* s1, const char_type* s2, size_t n);
      static char_type* copy(char_type* s1, const char_type* s2, size_t n);
      static char_type* move(char_type* s1, size_t n, char_type a);

      static int_type not_eof( const int_type& c );
      static char_type to_char_type( const int_type& c );
      static int_type to_int_type( const char_type& c );
      static bool eq_int_type( const int_type& c1, const int_type& c2 );
      static int_type eof();
   };

   template<>
   struct char_traits<wchar_t> {
      typedef wchar_t char_type;
      typedef int int_type;
      typedef streamoff off_type;
      typedef wstreampos pos_type;
      typedef mbstate_t state_type;

      static void assign(char_type& c1, const char_type& c2);
      static bool eq(const char_type& c1, const char_type& c2);
      static bool lt(const char_type& c1, const char_type& c2);
      static int compare( const char_type* sq, const char_type* s2,
                          size_t n );
      static size_t length( const char_type* s);
      static const char_type* find( const char_type* s, size_t n,
                                    const char_type& a);
      static char_type* move(char_type* s1, const char_type* s2, size_t n);
      static char_type* copy(char_type* s1, const char_type* s2, size_t n);
      static char_type* move(char_type* s1, size_t n, char_type a);

      static int_type not_eof( const int_type& c );
      static char_type to_char_type( const int_type& c );
      static int_type to_int_type( const char_type& c );
      static bool eq_int_type( const int_type& c1, const int_type& c2 );
      static int_type eof();
   };
}

#endif
