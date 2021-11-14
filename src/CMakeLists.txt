

add_executable(curl_playground main.cpp)
target_include_directories(curl_playground PRIVATE)
target_link_libraries(curl_playground PRIVATE ${CONAN_LIBS})