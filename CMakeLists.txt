# CMakeList.txt: proyecto de CMake para fin_predict, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (fin_predict "fin_predict.cpp" "fin_predict.h" "Precio.h" "carga_datos.h" "carga_datos.cpp" "main.cpp" "Estrategia.h" "CruceMediasMoviles.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET fin_predict PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
