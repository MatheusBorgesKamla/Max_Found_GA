#Versão CMake necessaria
cmake_minimum_required(VERSION 3.5.1)
#Nome do projeto
project(Peak_Found_GA)
#Setando padronização do compilador de gcc
set (CMAKE_CXX_STANDARD 11)
#Guardando os arquivos .cpp presentes na pasta src
file(GLOB SOURCES "src/*.cpp")
#Gerando executável a partir dos .cpp
add_executable(Executable ${SOURCES})
#Incluindo pasta para linkar os headers
target_include_directories( Executable PRIVATE "include")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Executable ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )