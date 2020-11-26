CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		helper.o

LIBS =

TARGET =	helper

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
