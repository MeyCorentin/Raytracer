##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

PP = g++
CC = gcc

SRC = src/main.cpp	\
		src/raytracer.cpp	\
		src/Math/Math.cpp \
		src/Material/Metal.cpp \
		src/Material/Mate.cpp \
		src/Objects/Shapes/hit_record.cpp \
		src/CreateObjects/CreateCamera.cpp	\
		src/CreateObjects/CreateLights.cpp	\
		src/CreateObjects/CreateShapes.cpp

clean = *.o


NAME = raytracer

${NAME}:
	@echo 'Files compiled'

all : ${NAME}
	@${PP} -o ${NAME} `pkg-config --cflags libconfig++` ${SRC} `pkg-config --libs libconfig++` -Iincludes -std=c++20 -Wall -g3

clean :
	@rm -rf ${clean}
	@echo 'Temporary files deleted'

fclean : clean
	@rm -rf ${NAME}
	@echo 'Executable deleted'

re : fclean all

.PHONY: re fclean clean all tests_run test
