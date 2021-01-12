CXX = g++
CXXFLAGS = -Wall -g
SDIR = src
ODIR = obj
OUT = application
INC = -Iheaders -I/usr/lib/glfw/include -I/usr/lib/glew/include -I/usr/lib/glm
LIB = /usr/lib/glfw/src/libglfw3.a /usr/lib/glew/lib/libGLEW.a -lpthread -lm -lz -lGL -lX11 -lXext -lXfixes -ldl

#for every .cpp file in project, there has to be a .o file here:
_OBJS = main.o loadshaders.o matrix.o object.o player.o rng.o raycaster.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -DGLEW_NO_GLU $< -o $@ $(INC)

$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(OUT) $^ $(LIB) 

clean:
	rm obj/*.o