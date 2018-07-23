aux_source_directory(. LIB_SRCS)

include_directories(..)

add_library(cpp_wrapper STATIC ${LIB_SRCS})

