project( CTextFileToMemory ) 
cmake_minimum_required( VERSION 2.8.7 )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/modules ${CMAKE_MODULE_PATH})
   

 

add_executable( 
               TestCTextFileToMemory 
               test.c  
               cTextFileToMemory.h
              )
 
target_link_libraries(TestCTextFileToMemory rt m pthread )   
       
 
set_target_properties(TestCTextFileToMemory PROPERTIES 
                       ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
                       LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
                       RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
                      )
