platform(cx16os COMPLETE HOSTED PARENT common)

if(NOT CMAKE_CROSSCOMPILING)
  return()
endif()

install(FILES
  cx16os.h
TYPE INCLUDE)
install(FILES link.ld TYPE LIB)

add_platform_library(cx16os-crt0
  crt0/crt0.s
)

install(FILES cx16.inc DESTINATION ${ASMINCDIR})

merge_libraries(cx16os-crt0
  common-crt0
  common-init-stack
  common-zero-bss
  common-exit-return
)

add_platform_library(cx16os-c
  delay.c
  getchar.c
  lcd.c
  putchar.c
)

target_compile_options(cx16os-crt0 PUBLIC -mcpu=mosw65816)
target_link_libraries(cx16os-crt0 PRIVATE common-asminc)

target_include_directories(cx16os-c BEFORE PUBLIC .)
target_compile_options(cx16os-c PUBLIC -mcpu=mosw65816)
target_link_libraries(cx16os-c PRIVATE common-asminc)
