
function(add_grammar_from_repo NAME REPO VERSION)
  # CPMAddPackage(
  #   NAME ${NAME}
  #   GIT_REPOSITORY ${REPO}
  #   VERSION ${VERSION}
  #   DOWNLOAD_ONLY YES
  # )

  if ("${${NAME}_ADDED}")
    add_library(${NAME} STATIC)

    file(GLOB maybe_scanner "${${NAME}_SOURCE_DIR}/src/scanner.c")
    target_sources(${NAME}
      PRIVATE
        "${${NAME}_SOURCE_DIR}/src/parser.c"
        ${maybe_scanner}
    )
    target_include_directories(${NAME}
      PRIVATE
        # parser.h is stored within the src directory, so we need to include
        # src in the search paths
        $<BUILD_INTERFACE:${${NAME}_SOURCE_DIR}/src>
      PUBLIC
        $<INSTALL_INTERFACE:include>
    )

    target_link_libraries(${NAME} PUBLIC
        tree_sitter
    )

    set_target_properties(${NAME} PROPERTIES LINKER_LANGUAGE CXX)

  endif()
endfunction(add_grammar_from_repo)

