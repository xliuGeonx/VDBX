# -*- cmake -*-
# - SimpleKernel.exe test case
#
# Author : Adam L. squall02167453@gmail.com

# -----------------------------------------------------------------------------
# ----------------------------- Project configuration -------------------------
# -----------------------------------------------------------------------------

# Environment
SET(VDBX_SimpleKernel_exe TestCase_SimpleKernel)
SET(VDBX_SimpleKernel_exe ${VDBX_SimpleKernel_exe} PARENT_SCOPE)

IF(TARGET ${VDBX_SimpleKernel_exe})
  MESSAGE("${VDBX_SimpleKernel_exe} is already defined.")
ELSE()
	#Add execute_process	
	LIST(APPEND CCUDA_SimpleKernel_exe_include_dir  ${CMAKE_CURRENT_SOURCE_DIR}/src)
	ADD_EXECUTABLE(${VDBX_SimpleKernel_exe} ${CCUDA_SimpleKernel_exe_include_dir}/main.cpp)

	#Add include
	LIST(APPEND CUDA_inlcude_dir ${CUDA_INCLUDE_DIRS})
	INCLUDE_DIRECTORIES( ${CUDA_inlcude_dir} ${Culib_LIB_INCLUDE_DIR})

	#FOREACH( f ${USED_DLLS})
    #ADD_CUSTOM_COMMAND(TARGET ${VDBX_SimpleKernel_exe} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${f} $<TARGET_FILE_DIR:${VDBX_SimpleKernel_exe}> )  
	#ENDFOREACH()
#SET_TARGET_PROPERTIES(${VDBX_SimpleKernel_exe} PROPERTIES LINKER_LANGUAGE CXX)

	#Add libs 
	LIST(APPEND CUDALinkedLibraries ${CUDA_LIBRARIES} ${Culib})
	LIST(REMOVE_DUPLICATES CUDALinkedLibraries)
	TARGET_LINK_LIBRARIES(${VDBX_SimpleKernel_exe} LINK_PUBLIC ${CUDALinkedLibraries})

ENDIF()