################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/QueueCircularArray.cpp \
../src/QueueLinked.cpp \
../src/show7.cpp \
../src/storesim.cpp 

OBJS += \
./src/QueueCircularArray.o \
./src/QueueLinked.o \
./src/show7.o \
./src/storesim.o 

CPP_DEPS += \
./src/QueueCircularArray.d \
./src/QueueLinked.d \
./src/show7.d \
./src/storesim.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


