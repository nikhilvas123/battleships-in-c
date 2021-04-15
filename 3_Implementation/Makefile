# Name of the project
PROJ_NAME = battleships

# Name of the test project
TEST_PROJ_NAME = test_$(PROJ_NAME)

# Output directory
BUILD_DIR = build

# All source code files
SRC = src/battleships.c

# All test source files
TEST_SRC = src/battleships.c\
test/test_battleships.c\
unity/unity.c\

# Covrage source file
COV_SRC = test_battleships.c

TEST_OUTPUT = $(BUILD_DIR)/Test_$(PROJ_NAME).out

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes

# Document files
DOCUMENTATION_OUTPUT = documentation/html

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Default target built
$(PROJ_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD_DIR)
	gcc project_main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# Call `make run` to run the application
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

# Run in dev mode
dev: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) dev	

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test: $(TEST_SRC) $(BUILD_DIR)
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD_DIR))
	$(RM) $(call FixPath,$(DOCUMENTATION_OUTPUT))
	$(RM) $(call FixPath,$(PROJ_NAME),$(PROJ_NAME).gcno)

# Create new build folder if not present
$(BUILD_DIR):
	mkdir build

# Static code analysis

cppcheck:
	cppcheck -i unity --enable=all .

# Coverage
coverage: ${PROJ_NAME}
	cp test/$(COV_SRC) .
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) $(COV_SRC)
# Dynamic check
dynamic: $(SRC) $(BUILD_DIR)
	gcc -fsanitize=address -fno-omit-frame-pointer project_main.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
