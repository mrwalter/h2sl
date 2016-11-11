find_path(H2SL_INCLUDE_DIR NAMES h2sl/pos.h
          HINTS /usr/local/include)

find_library(H2SL_COMMON_LIBRARY NAMES h2sl-common
              HINTS /usr/local/lib)

find_library(H2SL_SYMBOL_LIBRARY NAMES h2sl-symbol
              HINTS /usr/local/lib)

find_library(H2SL_LANGUAGE_LIBRARY NAMES h2sl-language
              HINTS /usr/local/lib)

find_library(H2SL_PARSER_LIBRARY NAMES h2sl-parser
              HINTS /usr/local/lib)

find_library(H2SL_LLM_LIBRARY NAMES h2sl-llm
              HINTS /usr/local/lib)

find_library(H2SL_DCG_LIBRARY NAMES h2sl-dcg
              HINTS /usr/local/lib)

find_library(H2SL_UTIL_LIBRARY NAMES h2sl-util
              HINTS /usr/local/lib)

set(H2SL_LIBRARIES ${H2SL_UTIL_LIBRARY} ${H2SL_DCG_LIBRARY} ${H2SL_LLM_LIBRARY} ${H2SL_PARSER_LIBRARY} ${H2SL_LANGUAGE_LIBRARY} ${H2SL_SYMBOL_LIBRARY} ${H2SL_COMMON_LIBRARY})

mark_as_advanced(H2SL_INCLUDE_DIR H2SL_LIBRARIES)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(h2sl FOUND_VAR h2sl_FOUND REQUIRED_VARS H2SL_LIBRARIES H2SL_INCLUDE_DIR)
