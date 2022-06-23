set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf")

add_library(acetest acetest.cpp)

target_include_directories(acetest
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

install(TARGETS acetest DESTINATION lib)
install(FILES acetest.h DESTINATION include)