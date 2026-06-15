cmake_minimum_required(VERSION 3.19)
project(oop_good LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(oop_good
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    student.h
    restaurant.h
    room.h
    dormitory.h
    university.h
    student.cpp
    room.cpp
    dormitory.cpp
    university.cpp
    restaurant.cpp
)

qt_add_translations(
    TARGETS oop_good
    TS_FILES oop_good_en_150.ts
)

target_link_libraries(oop_good
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS oop_good
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET oop_good
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
