add_executable(catchTest
	catchMain.cpp
	test_ctf.cpp
	)

target_link_libraries(catchTest Catch2::Catch2)
target_link_libraries(catchTest ${CMAKE_BINARY_DIR}/lib/librelion_lib.a)
target_link_libraries(catchTest fftw3)
target_link_libraries(catchTest tiff)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

target_include_directories(catchTest PRIVATE ${CMAKE_SOURCE_DIR})

include(CTest)
include(Catch)

catch_discover_tests(catchTest)


