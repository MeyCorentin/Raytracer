##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

PP = g++
CC = gcc

SRC = src/main.cpp	\
		src/Math/Math.cpp \
		src/Material/Metal.cpp \
		src/Material/Mate.cpp \
		src/Objects/Shapes/hit_record.cpp \

clean = *.o


NAME = raytracer

${NAME}:
	@echo 'Files compiled'

all : ${NAME}
	@${PP} -o ${NAME} ${SRC} -Iincludes -std=c++20 -Wall -g3

clean :
	@rm -rf ${clean}
	@echo 'Temporary files deleted'

fclean : clean
	@rm -rf ${NAME}
	@echo 'Executable deleted'

re : fclean all

.PHONY: re fclean clean all tests_run test
