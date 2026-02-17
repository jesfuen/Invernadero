# *****************************************************
# Makefile para compilar el proyecto con estructura modular
# *****************************************************

CC = g++
CFLAGS = -Wall -g -Isrc #-Isrc/exceptions
.RECIPEPREFIX = >

# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRC_DIR = src
USER_DIR = users
SENSOR_DIR = sensors
EXCEPTION_DIR = exceptions

SOURCES = \
main.cpp \
Database.cpp \
utils.cpp \
$(USER_DIR)/User.cpp \
$(USER_DIR)/Admin.cpp \
$(USER_DIR)/Guest.cpp \
$(USER_DIR)/SuperAdmin.cpp \
$(SENSOR_DIR)/Sensor.cpp \
$(SENSOR_DIR)/SensorTemperatura.cpp \
$(SENSOR_DIR)/SensorRadiacion.cpp \
$(SENSOR_DIR)/SensorAire.cpp \
$(SENSOR_DIR)/SensorHumedad.cpp \
$(SENSOR_DIR)/CamaraTermica.cpp \
$(EXCEPTION_DIR)/SensorExceptions.cpp \
$(EXCEPTION_DIR)/UserExceptions.cpp \


OBJECTS = $(SOURCES:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJECTS)
>$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Regla para compilar cualquier archivo fuente
%.o: %.cpp
>$(CC) $(CFLAGS) -c $< -o $@

# Regla especial para main (si no tiene .h)
$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp
>$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
>rm -f *.o $(USER_DIR)/*.o $(SENSOR_DIR)/*.o $(EXCEPTION_DIR)/*.o $(TARGET)
