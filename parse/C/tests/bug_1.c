
extern void kmap_init(void) __init;

extern void FASTCALL(kunmap_high(struct page *page));

static inline void *kmap(struct page *page)
{
}

