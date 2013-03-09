################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MainObjects/GUI.cpp \
../MainObjects/Parser.cpp \
../MainObjects/Player.cpp \
../MainObjects/Random.cpp \
../MainObjects/TrackPos.cpp \
../MainObjects/main.cpp 

OBJS += \
./MainObjects/GUI.o \
./MainObjects/Parser.o \
./MainObjects/Player.o \
./MainObjects/Random.o \
./MainObjects/TrackPos.o \
./MainObjects/main.o 

CPP_DEPS += \
./MainObjects/GUI.d \
./MainObjects/Parser.d \
./MainObjects/Player.d \
./MainObjects/Random.d \
./MainObjects/TrackPos.d \
./MainObjects/main.d 


# Each subdirectory must supply rules for building sources it contributes
MainObjects/%.o: ../MainObjects/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/lib/gcc/i686-linux-gnu/4.7/include-fixed -I/opt/include/ -I/usr/local/include -I/usr/include -I/usr/include/c++/4.7 -I/usr/include/c++/4.7/backward -I/usr/include/c++/4.7/i686-linux-gnu -I/usr/include/i386-linux-gnu -I/usr/lib/gcc/i686-linux-gnu/4.7/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


