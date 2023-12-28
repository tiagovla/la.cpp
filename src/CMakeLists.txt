add_library(lacpp_core INTERFACE)

set(LACPP_HEADERS ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(lacpp_core INTERFACE ${LACPP_HEADERS})
