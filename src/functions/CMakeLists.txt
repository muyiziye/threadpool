project(threadpool)

include_directories(
    .
    ${EXTLIBS_PATH}/include/
)

set(${PROJECT_NAME}_SRC 
    threadpool.cpp
)


find_library(LOGSYSTEM_PATH NAMES logsystem HINTS ${EXTLIBS_PATH}/lib/)

add_library( ${PROJECT_NAME} SHARED
    ${${PROJECT_NAME}_SRC} 
    )

add_library( ${PROJECT_NAME}_static STATIC
    ${${PROJECT_NAME}_SRC} 
    )

target_link_libraries(${PROJECT_NAME}
    ${LOGSYSTEM_PATH}
    pthread
    )

target_link_libraries(${PROJECT_NAME}_static
    ${LOGSYSTEM_STATIC_PATH}
    pthread
    )

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static
    DESTINATION ${OUTPUT_PATH}/lib/ 
    )
