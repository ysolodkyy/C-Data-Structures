################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BSTree2.cpp \
../src/show9.cpp \
../src/test9.cpp 

OBJS += \
./src/BSTree2.o \
./src/show9.o \
./src/test9.o 

CPP_DEPS += \
./src/BSTree2.d \
./src/show9.d \
./src/test9.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


