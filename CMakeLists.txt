cmake_minimum_required(VERSION 2.8)
set(PROJECT kconfig-xt-test)
set(CMAKE_MODULE_PATH ${kconfig-xt-test_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include(${QT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} ${KDE4_INCLUDES} ${QT_INCLUDE_DIRS})

set(KCONFIG_XT_TEST_SRCS main.cpp mainwindow.cpp)

kde4_add_ui_files(KCONFIG_XT_TEST_SRCS configurator.ui mainwindow.ui)
kde4_add_kcfg_files(KCONFIG_XT_TEST_SRCS configurator.kcfgc)

kde4_add_executable(${PROJECT} ${KCONFIG_XT_TEST_SRCS})
target_link_libraries(${PROJECT} ${QT_LIBRARIES} ${KDE4_KIO_LIBS})

install(TARGETS ${PROJECT} ${INSTALL_TARGETS_DEFAULT_ARGS})
