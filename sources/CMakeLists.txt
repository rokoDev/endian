target_sources(endian
	PRIVATE
    include/endian/endian.h
  )

include(TestBigEndian)
test_big_endian(HOST_BIG_ENDIAN)
if(HOST_BIG_ENDIAN)
  target_compile_definitions(endian INTERFACE HOST_BIG_ENDIAN)
endif()

set_property(TARGET endian APPEND PROPERTY SRC_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")
target_include_directories(endian INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
