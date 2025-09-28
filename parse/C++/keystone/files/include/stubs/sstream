#ifndef _SSTREAM_
#define _SSTREAM_

#include <iterator>
#include "allocator.h"
#include <string>
#include <iostream>

namespace std {
   template<class charT, class traits,
            class Allocator >
   class basic_stringbuf : public basic_streambuf<charT, traits> {
   public:
      typedef charT char_type;
      typedef typename traits::int_type int_type;
      typedef typename traits::pos_type pos_type;
      typedef typename traits::off_type off_type;
      typedef traits traits_type;

      explicit basic_stringbuf(ios_base::openmode which =
                               ios_base::in | ios_base::out);
      explicit basic_stringbuf( const basic_string<charT, traits,Allocator>& str,
                                ios_base::openmode which = ios_base::in | ios_base::out );

      basic_string<charT,traits,Allocator> str() const;
      void str(const basic_string<charT,traits,Allocator>& s);
   protected:
      virtual int_type underflow();
      virtual int_type pbackfail(int_type c = traits::eof());
      virtual int_type overflow(int_type c = traits::eof());
      virtual basic_streambuf<charT,traits>* setbuf(charT*, streamsize);

      virtual pos_type seekoff(off_type off, ios_base::seekdir way,
                               ios_base::openmode which =
                               ios_base::in | ios_base::out);

      virtual pos_type seekoff(pos_type sp,
                               ios_base::openmode which =
                               ios_base::in | ios_base::out);
      
   };

   typedef basic_stringbuf<char> stringbuf;
   typedef basic_stringbuf<wchar_t> wstringbuf;

   template<class charT, class traits ,
            class Allocator  >
   class basic_istringstream : public basic_istream<charT, traits> {
   public:
      typedef charT char_type;
      typedef typename traits::int_type int_type;
      typedef typename traits::pos_type pos_type;
      typedef typename traits::off_type off_type;
      typedef traits traits_type;

      explicit basic_istringstream(ios_base::openmode which = ios_base::in);
      explicit basic_istringstream(const basic_string<charT,traits,Allocator>& str,
                                   ios_base::openmode which = ios_base::in);

      basic_stringbuf<charT,traits,Allocator>* rdbuf() const;
      basic_string<charT,traits,Allocator> str() const;
      void str(const basic_string<charT,traits,Allocator>& s);
   };

   typedef basic_istringstream<char> istringstream;
   typedef basic_istringstream<wchar_t> wistringstream;

   // backwards compatability
   typedef basic_istringstream<char> istrstream;
   typedef basic_istringstream<wchar_t> wistrstream;

   template<class charT, class traits,
            class Allocator >
   class basic_ostringstream : public basic_ostream<charT,traits> {
   public:
      typedef charT char_type;
      typedef typename traits::int_type int_type;
      typedef typename traits::pos_type pos_type;
      typedef typename traits::off_type off_type;
      typedef traits traits_type;

      explicit basic_ostringstream(ios_base::openmode which = ios_base::out);
      explicit basic_ostringstream(const basic_string<charT,traits,Allocator>& str,
                                   ios_base::openmode which = ios_base::out);

      basic_stringbuf<charT,traits,Allocator>* rdbuf() const;
      basic_string<charT,traits,Allocator> str() const;
      void str(const basic_string<charT,traits,Allocator>& s);      
   };

   typedef basic_ostringstream<char> ostringstream;
   typedef basic_ostringstream<wchar_t> wostringstream;

   // backwards compatability
   typedef basic_ostringstream<char> ostrstream;
   typedef basic_ostringstream<wchar_t> wostrstream;

   template<class charT, class traits,
            class Allocator >
   class basic_stringstream {
   public:
      typedef charT char_type;
      typedef typename traits::int_type int_type;
      typedef typename traits::pos_type pos_type;
      typedef typename traits::off_type off_type;
      typedef traits traits_type;

      explicit basic_stringstream(ios_base::openmode which =
                                  ios_base::in | ios_base::out);
      explicit basic_stringstream(const basic_string<charT,traits,Allocator>& str,
                                  ios_base::openmode which =
                                  ios_base::in | ios_base::out);

      basic_stringbuf<charT,traits,Allocator>* rdbuf() const;
      basic_string<charT,traits,Allocator> str() const;
      void str(const basic_string<charT,traits,Allocator>& s);            
   };

   typedef basic_stringstream<char> stringstream;
   typedef basic_stringstream<wchar_t> wstringstream;
}
#endif
