// IF, PRIMARY_index
#ifdef STRINGIFY
"
#endif

#ifdef INTERPRETER_MODE
IF:

#ifdef CLIT
PRINT("\n",0,0,0)
#endif

if(*temp[0])
{
  ADVANCE_HEAD
}
else
{
  INDEX_AT(head_index) += 1 + core_programs_arguments[AT_HEAD_OFFSET(0)]; //ADVANCE_HEAD once, but don't execute
  ADVANCE_HEAD
}
#endif

#ifdef NAME_MODE
IF
#endif

#ifdef LABEL_MODE
&&IF
#endif

#ifdef ARGUMENTS_MODE
1
#endif

#ifdef STRINGIFY
"
#endif

#ifdef ENUMERATE
,
#endif
