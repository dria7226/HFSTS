#ifdef IMPLEMENTATION_MODE
NAME :

#ifdef IMPLEMENTATION_1
IMPLEMENTATION_1
#endif

#ifdef CLIT
#ifdef CLIT_1
CLIT_1
#endif
#endif

#ifdef IMPLEMENTATION_2
IMPLEMENTATION_2
#endif

#ifdef CLIT
#ifdef CLIT_2
CLIT_2
#endif
#endif

#ifdef IMPLEMENTATION_3
IMPLEMENTATION_3
#endif

#ifdef CLIT
#ifdef CLIT_3
CLIT_3
#endif
#endif

goto advance_head;
#endif

#define retrieve(content) content

#ifdef TURN_TO_LABEL
#undef retrieve
#define retrieve(content) &&content
#endif

#ifdef TURN_TO_STRING
#undef retrieve
#define internal_retrieve(content) #content
#define retrieve(content) internal_retrieve(content)
#endif

#ifdef NAME_MODE
retrieve(NAME)
#endif

#ifdef ARGUMENTS_MODE
retrieve(ARGUMENTS)
#endif

#ifdef ENUMERATE
,
#endif

#undef NAME
#undef ARGUMENTS
#undef internal_retrieve
#undef retrieve

#undef IMPLEMENTATION_1
#undef CLIT_1
#undef IMPLEMENTATION_2
#undef CLIT_2
#undef IMPLEMENTATION_3
#undef CLIT_3
