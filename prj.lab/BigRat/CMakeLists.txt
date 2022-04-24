add_library(bigRational bigRational.h bigRational.cpp)
set_property(TARGET bigRational PROPERTY CXX_STANDARD 14)

add_executable(bigrational_test bigRat_test.cpp)
target_link_libraries(bigrational_test bigRational bigInt)