# Makefile for compiling C code

# Output directory
OUTDIR := .output

# Compiler flags
CFLAGS := -lglut -lGLU -lGL -lm -lGLEW -lSOIL -lglm -lglfw

# Create output directory if it doesn't exist
$(shell mkdir -p $(OUTDIR))

# Compile .c files to .o files
$(OUTDIR)/%.o: %.cpp
	g++ -c $< -o $@ $(CFLAGS)

# Build the final executable: build.<filename>
build.%: $(OUTDIR)/%.o
	g++ $^ -o $(OUTDIR)/$* $(CFLAGS)
	./$(OUTDIR)/$*
