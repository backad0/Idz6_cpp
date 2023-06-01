add_test([=[MyDictionary.Test]=]  [==[C:/Users/alesh/CLionProjects/c++ programing university/Idz6/cmake-build-debug/main.exe]==] [==[--gtest_filter=MyDictionary.Test]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MyDictionary.Test]=]  PROPERTIES WORKING_DIRECTORY [==[C:/Users/alesh/CLionProjects/c++ programing university/Idz6/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  main_TESTS MyDictionary.Test)
