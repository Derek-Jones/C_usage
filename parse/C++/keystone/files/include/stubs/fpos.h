
#ifndef __STD_FPOS
#define __STD_FPOS

namespace std
{
   template <class> class fpos;
	typedef long _STATE;
   typedef fpos <_STATE> streampos;
   typedef fpos <_STATE> wstreampos;
   //typedef fpos <char_traits<char>::state_type>    streampos;
   //typedef fpos <char_traits<wchar_t>::state_type> wstreampos;
}   

#endif
