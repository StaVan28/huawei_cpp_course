#--------------------------------------------------------------------------------------
# ANNOTATION
#--------------------------------------------------------------------------------------

# Makefile for complex_project
# version 1.1
#		author: Starchenko Ivan

#--------------------------------------------------------------------------------------
# SETTINGS
#--------------------------------------------------------------------------------------

# project name
PROJECT = complex

# choose release or debug mode
LAUNCH_MODE = debug

Q = @  
E = $(Q) echo

# path for directories
BIN_DIR  = Bin
SRC_DIR  = Src
HDR_DIR  = Include
OBJ_DIR  = Obj
TST_DIR  = Tests
INCL_DIR = $(HDR_DIR) $(TST_DIR)

# Source
BIN  = $(BIN_DIR)/$(PROJECT)
HDR  = $(HDR_DIR)/$(PROJECT).h   $(TST_DIR)/tests.h
SRC  = $(SRC_DIR)/$(PROJECT).cpp $(TST_DIR)/tests.cpp $(SRC_DIR)/main.cpp 
OBJ  = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC)))
OBJ := $(OBJ:%.cpp=%.o)
DEP  = $(OBJ:%.o=%.d)
LIB  = $(addprefix lib, $(addsuffix .a, $(notdir $(BIN))))

# find a *.cpp *.h files 
vpath %.cpp $(SRC_DIR) $(TST_DIR)
vpath %.h   $(HDR_DIR) $(TST_DIR)

# compiler settings
CXX      = g++ -std=c++14
CXXFLAGS = -MMD
WARNINGS = -Wall -Wextra -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy \
           -Wenum-compare -Wfloat-equal -Wnon-virtual-dtor -Wold-style-cast \
           -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo

DEBUG_MODE   = -g3 -O0
RELEASE_MODE = -g0 -O2

VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all -v

ifeq ($(LAUNCH_MODE),debug)
	CXXFLAGS += $(DEBUG_MODE)
else
	CXXFLAGS += $(RELEASE_MODE)
endif

#--------------------------------------------------------------------------------------
# RULES
#--------------------------------------------------------------------------------------

.PHONY: debug release default

#
## launch with debug valgrind(default)
default: $(LAUNCH_MODE)

debug: $(BIN) 
	$(E) "    LAUNCH(DBG): " $(BIN)
	$(Q) valgrind $(BIN)

release: clean $(BIN)
	$(E) "    LAUNCH(RLS): " $(BIN)
	$(Q) $(BIN)

#
## linking
$(BIN): $(OBJ)
	$(E) "    LINK:        " $@
	$(Q) $(CXX) $(WARNINGS) $^ -o $@

#
## compiling
$(OBJ_DIR)/%.o: %.cpp
	$(E) "    C++:         " $@
	$(Q) ${CXX} -c  ${CXXFLAGS} $(addprefix -I, $(INCL_DIR)) $< -o $@

$(OBJ_DIR)/$(PROJECT).o: $(PROJECT).cpp $(PROJECT).h 
$(OBJ_DIR)/main.o:             main.cpp $(PROJECT).h tests.h
$(OBJ_DIR)/tests.o:           tests.cpp $(PROJECT).h tests.h

#
## additional features
.PHONY: clean tags rebuild git no_valgrind unit_tests library log full_check_valgrind print_logs

install:
	$(E) " INSTALL"
	$(Q) mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
	$(E) "  CLEAN"
	$(Q) rm -f $(BIN) $(BIN_TESTS) $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d

tags: ${SRC}
	$(Q) rm -f tags
	$(Q) ctags -R -f .tags

gdb: $(BIN)
	$(E) "    GDB:        " $(BIN)
	$(Q) gdb $(BIN) 

rebuild: clean default

no_valgrind: $(BIN)
	$(E) "  LAUNCH STD: " $(BIN)
	$(Q) $(BIN)

full_check_valgrind: $(BIN)
	$(E) "  LAUNCH FULL:" $(BIN)
	$(Q) valgrind  $(VALGRIND_FLAGS) $(BIN)

log:
	$(Q) git log --oneline --all --graph

print_logs:
	$(E) "    PRINT LOGS  "

#
## generate static lib 
$(PROJ_LIB): $(OBJ)
	$(Q) ar cr $@ $^