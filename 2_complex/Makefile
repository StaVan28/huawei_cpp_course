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
export PROJECT = complex

# choose release or debug mode
LAUNCH_MODE = debug

export Q = @  
export E = $(Q) echo

# path for directories
export BIN_DIR = Bin
export SRC_DIR = Src
export HDR_DIR = Include
export OBJ_DIR = Obj
export TST_DIR = Tests

# Files
BIN       = $(BIN_DIR)/$(PROJECT)
BIN_TESTS = $(BIN_DIR)/$(PROJECT)_tests

# compiler settings
export CXX      = g++ -std=c++14
export CXXFLAGS = -MMD
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

debug: $(PROJECT) 
	$(E) "    LAUNCH(DBG): " $(BIN)
	$(Q) valgrind $(BIN)

release: clean $(PROJECT)
	$(E) "    LAUNCH(RLS): " $(BIN)
	$(Q) $(BIN)

$(PROJECT):
	$(E) "    MAKE RECUR(compile):" $(BIN)
	$(Q) $(MAKE) -C $(SRC_DIR)

tests:
	$(E) "    MAKE RECUR(compile): " $(BIN_TESTS)
	$(Q) $(MAKE) -C $(TST_DIR)
	$(E) "    LAUNCH:              " $(BIN_TESTS)
	$(Q) $(BIN_TESTS)

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