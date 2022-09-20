find_package(GTest)

set(UT unit_test)

set(UT_SOURCES
  main.cpp
  test_counting_sort.cpp
)

add_executable(${UT} ${UT_SOURCES})
target_link_libraries(${UT}
  gtest
  gtest_main
)
