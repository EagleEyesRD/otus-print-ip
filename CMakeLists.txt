cmake_minimum_required(VERSION 3.5)

project(print-ip  VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(print-ip main.cpp)
set_target_properties(print-ip PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


if (MSVC)
    target_compile_options(print-ip PRIVATE
        /W4
    )
else ()
    target_compile_options(print-ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS print-ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT markessm@yandex.ru)

include(CPack)