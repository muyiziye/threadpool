project(unittest)

include_directories(
    ${EXTLIBS_PATH}/include/
    ../functions/
)

set(${PROJECT_NAME}_SRC 
    main.cpp
)

find_library(LOGSYSTEM_PATH NAMES logsystem HINTS ${EXTLIBS_PATH}/lib/)
find_library(LOGSYSTEM_STATIC_PATH NAMES logsystem_static HINTS ${EXTLIBS_PATH}/lib/)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
add_executable(${PROJECT_NAME}_static ${${PROJECT_NAME}_SRC})

target_link_libraries(${PROJECT_NAME} 
    ${LOGSYSTEM_PATH}
    threadpool
)

target_link_libraries(${PROJECT_NAME}_static 
    ${LOGSYSTEM_STATIC_PATH}
    threadpool_static
)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static 
    DESTINATION ${OUTPUT_PATH}/bin
)
