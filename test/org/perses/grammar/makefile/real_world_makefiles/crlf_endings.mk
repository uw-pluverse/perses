CC = cl
OBJS = a.obj b.obj

app.exe: $(OBJS)
	link /OUT:$@ $(OBJS)
