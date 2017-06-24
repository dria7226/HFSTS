#ifdef IMPLEMENTATION_MODE
NAME :

IMPLEMENTATION

#ifdef CLIT
CLIT_1
#endif

IMPLEMENTATION_2

#ifdef CLIT
CLIT_2
#endif

IMPLEMENTATION_3

#ifdef CLIT
CLIT_3
#endif

ADVANCE_HEAD
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

#undef IMPLEMENTATION
#undef CLIT_1
#undef IMPLEMENTATION_2
#undef CLIT_2
#undef IMPLEMENTATION_3
#undef CLIT_3
