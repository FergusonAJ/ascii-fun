CC := gcc
CXX := g++
LDFLAGS := -lstdc++ -lm -lncurses
TARGET_EXEC ?= game.out
BIN_DIR ?=./bin
SRC_DIR ?=./src
INC_DIR ?=./include

SRCS := $(shell find $(SRC_DIR) \( -iname *.cpp -o -iname *.c -o -iname *.s \) )
OBJS := $(SRCS:%=$(BIN_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

#INCDIRS := $(shell find $(SRC_DIRS) -type d)
INCDIRS := $(shell find $(INC_DIR) -type d)
INCFLAGS := $(addprefix -I, $(INCDIRS))
CPPFLAGS ?= $(INCFLAGS) -MMD -MP -std=c++11

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

#assembly
$(BIN_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

#c
$(BIN_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

#cpp
$(BIN_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

#cleaning this
.PHONY: clean

#removing old builds by deleting the entire build dir
clean: 
	$(RM) -r $(BIN_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

print-%  : ; @echo $* = $($*)

#based on source: https://spin.atomicobject.com/2016/08/26/makefile-c-projects/

#"Function" for print-VARIABLE by Anthony Earl Wong here:
#https://stackoverflow.com/questions/16467718/how-to-print-out-a-variable-in-makefile
