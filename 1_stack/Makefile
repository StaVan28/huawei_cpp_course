#--------------------------------------------------------------------------------------
# ANNOTATION
#--------------------------------------------------------------------------------------

# Makefile for stack_project
# version 1.2
#		author: Starchenko Ivan

#--------------------------------------------------------------------------------------
# SETTINGS
#--------------------------------------------------------------------------------------

# choose release or debug mode
LAUNCH_MODE = debug

Q = @  
E = $(Q) echo

# path for directories
BIN_DIR = Bin
SRC_DIR = Src
HDR_DIR = Include
OBJ_DIR = Obj
TXT_DIR = Txt

# source
BIN  = $(BIN_DIR)/stack
HDR  = $(HDR_DIR)/stack.hpp
SRC  = $(SRC_DIR)/main.cpp  
OBJ  = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC)))
OBJ := $(OBJ:%.cpp=%.o)
DEP  = $(OBJ:%.o=%.d)
LIB  = libstack.a

# find a *.hpp files 
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(HDR_DIR)

# compiler settings
CXX      = g++ -std=c++11
WARNINGS = -Wall -Wextra -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy \
           -Wenum-compare -Wfloat-equal -Wnon-virtual-dtor -Wold-style-cast \
           -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo
CXXFLAGS = 

DEBUG_MODE   = -g3 -O0
RELEASE_MODE = -g0 -Ofast

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
default: print_logs

print_logs: $(LAUNCH_MODE)

debug: $(BIN) 
	$(E) "  LAUNCH(DBG):" $(BIN)
	$(Q) valgrind $(BIN)

release: clean  $(BIN)
	$(E) "  LAUNCH(RLS):" $(BIN)
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
	$(Q) ${CXX} -c ${CXXFLAGS} $(addprefix -I,$(HDR_DIR)) $< -o $@

$(OBJ_DIR)/main.o:    main.cpp stack.hpp


#
## additional features
.PHONY: clean errors tags rebuild git no_valgrind unit_tests library log full_check_valgrind print_logs

#
## additional features
.PHONY: clean tags rebuild git no_valgrind unit_tests library log full_check_valgrind print_logs

install:
	$(E) " INSTALL"
	$(Q) mkdir -p $(OBJ_DIR) $(BIN_DIR) $(TXT_DIR)

clean:
	$(E) "  CLEAN"
	$(Q) rm -f $(BIN) tags $(OBJ_DIR)/*.o

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
	$(Q) cat $(TXT_DIR)/dump_stack.txt

#
## generate static lib 
$(PROJ_LIB): $(OBJ)
	$(Q) ar cr $@ $^

-include $(DEP)