
#if 0
1
2
3
#else
int i;
#endif

#if 1
int j;
#else
1
2
3
4
5
#endif

#if 0
1
2
#endif

#if 1
int j;
#if 0
1
#endif
#else
1
2
3
4
5
#endif


