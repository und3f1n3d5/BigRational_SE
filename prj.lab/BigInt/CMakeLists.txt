add_library(bigInt bigInt.h bigInt.cpp)
set_property(TARGET bigInt PROPERTY CXX_STANDARD 14)

add_executable(bigint_test bigInt_test.cpp)
target_link_libraries(bigint_test bigInt)