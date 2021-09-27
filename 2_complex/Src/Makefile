#--------------------------------------------------------------------------------------
# ANNOTATION
#--------------------------------------------------------------------------------------

# Makefile for complex_modul
# version 1.0
#		author: Starchenko Ivan

#--------------------------------------------------------------------------------------
# SETTINGS
#--------------------------------------------------------------------------------------

# source
BIN  = ../$(BIN_DIR)/$(PROJECT)
HDR  = ../$(HDR_DIR)/$(PROJECT).hpp ../$(HDR_DIR)/consts.hpp ../$(HDR_DIR)/double.hpp
SRC  = main.cpp $(PROJECT).cpp double.cpp
OBJ  = $(addprefix ../$(OBJ_DIR)/, $(notdir $(SRC)))
OBJ := $(OBJ:%.cpp=%.o)
DEP  = $(OBJ:%.o=%.d)
LIB  = $(addprefix lib, $(addsuffix .a, $(notdir $(BIN))))

# find a *.cpp *.hpp files 
vpath %.cpp .
vpath %.hpp ../$(HDR_DIR)

#--------------------------------------------------------------------------------------
# RULES
#--------------------------------------------------------------------------------------

#
## linking
$(BIN): $(OBJ)
	$(E) "    LINK:        " $@
	$(Q) $(CXX) $(WARNINGS) $^ -o $@ 

#
## compiling
../$(OBJ_DIR)/%.o: %.cpp
	$(E) "    C++:         " $@
	$(Q) ${CXX} -c  ${CXXFLAGS} $(addprefix -I,../$(HDR_DIR)) $< -o $@

../$(OBJ_DIR)/main.o:             main.cpp $(PROJECT).hpp
../$(OBJ_DIR)/$(PROJECT).o: $(PROJECT).cpp $(PROJECT).hpp consts.hpp double.hpp
../$(OBJ_DIR)/double.o:         double.cpp     double.hpp

-include $(DEP) 