add_executable(catchTest
	catchMain.cpp
	test_getCTF.cpp)

enable_testing()

add_test(NAME getCTF COMMAND catchTest)
