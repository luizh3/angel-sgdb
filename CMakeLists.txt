cmake_minimum_required(VERSION 3.14)

project(Angel VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Sql Core Quick Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql Core Quick Concurrent )

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        model/connection/database/connectiondatabasemodel.h model/connection/database/connectiondatabasemodel.cpp
        control/mainscreencontrol.h control/mainscreencontrol.cpp
        control/connectiondatabasecontrol.h control/connectiondatabasecontrol.cpp
        controller/connectiondatabasecontroller.h controller/connectiondatabasecontroller.cpp
        delegate/connectiondatabasedelegate.h delegate/connectiondatabasedelegate.cpp
        service/connectiondatabaseservice.h service/connectiondatabaseservice.cpp
        service/config/applicationpropertiesservice.h service/config/applicationpropertiesservice.cpp
        service/exception/serviceexception.h service/exception/serviceexception.cpp
)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

# Adjust this path
set(POSTGRES_INCLUDE "C:/include" )
set(PATH_POSTGRES_LIB "C:/bin")

message(NOTICE "$$PWD/components")

set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR}/components CACHE STRING "Qt Creator extra qml import paths" FORCE)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Angel
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Angel APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Angel SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Angel
          ${PROJECT_SOURCES}
          control/screen.h control/screen.cpp
          control/control.h control/control.cpp
          control/handlercalls.h control/handlercalls.cpp
          control/basehandlercalls.h control/basehandlercalls.cpp
          control/chaincallshandler.h control/chaincallshandler.cpp
          control/mainscreencontrol.h control/mainscreencontrol.cpp
          utils/synctask.h utils/synctask.cpp
          service/databaseservice.h service/databaseservice.cpp
          model/database/databasemodel.h model/database/databasemodel.cpp
          controller/databasecontroller.h controller/databasecontroller.cpp
          control/database/databasecontrol.h control/database/databasecontrol.cpp
          utils/databasesingleton.h utils/databasesingleton.cpp
          utils/sqlqueryfile.h utils/sqlqueryfile.cpp
          utils/filehelper.h utils/filehelper.cpp
          sqls.qrc
          model/database/tablemodel.h model/database/tablemodel.cpp
          model/database/columnmodel.h model/database/columnmodel.cpp
          repository/databaserepository.h repository/databaserepository.cpp
          view/model/tabledatamodel.cpp view/model/tabledatamodel.h
          view/model/tablequeryresultmodel.h view/model/tablequeryresultmodel.cpp
          control/querypanelcontrol.h control/querypanelcontrol.cpp
          controller/querycontroller.h controller/querycontroller.cpp
          service/queryservice.h service/queryservice.cpp
          repository/queryrepository.h repository/queryrepository.cpp
          utils/sqlrecordfile.h utils/sqlrecordfile.cpp
          model/query/querymodel.h model/query/querymodel.cpp
          view/model/text/textdocumenthandlermodel.h view/model/text/textdocumenthandlermodel.cpp
          view/model/text/sqlsyntaxhighlighter.h view/model/text/sqlsyntaxhighlighter.cpp
        )
    endif()
endif()

target_include_directories(Angel PUBLIC
    ${BASEPATH}
    ${POSTGRES_INCLUDE}
)

message(NOTICE "${PATH_POSTGRES_LIB}")

find_library(PSQL_LIB pq PATHS ${PATH_POSTGRES_LIB})

if(PSQL_LIB)
    message(STATUS "Lib do PSQL encontrada!")
else()
    message(FATAL_ERROR "Lib do PSQL não encontrada!")
endif()

target_link_libraries(Angel
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Concurrent ${PSQL_LIB} ${NOTO_QT_LIB} )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Angel)
endif()
set_target_properties(Angel PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Angel
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(Angel)
    qt_finalize_executable(Angel)
endif()
