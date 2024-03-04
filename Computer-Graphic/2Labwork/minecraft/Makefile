# Compiler flags

CFLAGS := -lglut -lGLU -lGL -lm -lGLEW -lSOIL -lglm -lglfw
CXX := g++
OUTDIR = .out

# Create the output directory if it doesn't exist
$(shell mkdir -p $(OUTDIR))

# common folder
COMMON = ./common

SRCS =  $(COMMON)/shader.cpp \
	$(COMMON)/texture.cpp \
	$(COMMON)/controls.cpp \
	diamond.cpp \

OBJS = $(SRCS:%.c=$(OUTDIR)/%.o)

# Pattern rule for object file creation
$(OUTDIR)/%.o: %.cpp
	echo "Compiling $<"
	g++ -c $< -o $(OUTDIR)/$@ $(CFLAGS)


$(OUTDIR)/coal.o: coal.cpp
	g++ -c $< -o $(OUTDIR)/coal.o $(CFLAGS)

# New rule for final.o
final: $(OBJS)
	g++ -o $(OUTDIR)/final $^ $(CFLAGS)
	./$(OUTDIR)/final


coal: $(OUTDIR)/coal.o
	g++ -o $(OUTDIR)/coal $^ $(CFLAGS)
	rm $(OUTDIR)/coal.o
	./$(OUTDIR)/coal
	
