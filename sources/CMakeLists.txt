target_sources(endian
	PRIVATE
    include/endian/endian.h
    include/endian/details/bswap_intrinsics.h
    include/endian/details/bswap.h
    include/endian/details/typedefs.h
    include/endian/details/load.h
    include/endian/details/store.h
    include/endian/details/enum.h
    include/endian/details/convert.h
  )

include(TestBigEndian)
test_big_endian(HOST_BIG_ENDIAN)
if(HOST_BIG_ENDIAN)
  target_compile_definitions(endian INTERFACE HOST_BIG_ENDIAN)
endif()

target_include_directories(endian INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
