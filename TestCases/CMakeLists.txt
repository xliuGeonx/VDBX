# -*- cmake -*-
# - VDBX TestCases
# Author : Adam L. squall02167453@gmail.com
SET(TestCases_Name ${PROJECT_NAME}TestCases)
SET(${TestCases_Name} FALSE CACHE BOOL "Generate TestCases for ${TestCases_Name} default OFF")

IF(${TestCases_Name})
	LIST(APPEND InitalTests SimpleKernel DeviceQ)
	FOREACH(item ${InitalTests})
		ADD_SUBDIRECTORY(${item})
	ENDFOREACH()
ENDIF()