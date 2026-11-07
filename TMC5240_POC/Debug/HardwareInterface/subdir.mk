################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HardwareInterface/HI_SPI_1.c 

C_DEPS += \
./HardwareInterface/HI_SPI_1.d 

CREF += \
TMC5240_POC.cref 

OBJS += \
./HardwareInterface/HI_SPI_1.o 

MAP += \
TMC5240_POC.map 


# Each subdirectory must supply rules for building sources it contributes
HardwareInterface/%.o: ../HardwareInterface/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m85 -mthumb -mlittle-endian -mfloat-abi=hard -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -flax-vector-conversions -fshort-enums -fno-unroll-loops -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra_cfg\\fsp_cfg\\bsp" -I"." -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra_gen" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra_cfg\\fsp_cfg" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\src" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra\\fsp\\inc" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra\\fsp\\inc\\api" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra\\fsp\\inc\\instances" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\Application" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\DriverLayer" -I"C:\\My_Files\\PROJECTS\\TMC5240\\gitrepo\\TMC5240_POC\\HardwareInterface" -D_RENESAS_RA_ -D_RA_CORE=CM85 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

