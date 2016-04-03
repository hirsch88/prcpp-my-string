################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MyString.cpp \
../src/MyString_test.cpp \
../src/Test.cpp \
../src/main.cpp 

OBJS += \
./src/MyString.o \
./src/MyString_test.o \
./src/Test.o \
./src/main.o 

CPP_DEPS += \
./src/MyString.d \
./src/MyString_test.d \
./src/Test.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -D__GXX_EXPERIMENTAL_CXX0X__ -I"/Users/hirsch/Documents/fhnw/prcpp/my-string/MyString" -I"/Users/hirsch/Documents/fhnw/prcpp/my-string/MyString/cute" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


