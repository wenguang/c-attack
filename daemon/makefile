cc = gcc
objs = daeml.o
exe = daeml

$(exe): $(objs)
	cc $(objs) -o $@
daeml.o: daeml.c
	cc -c $< -o $@

clean:
	rm -rf $(exe) *.o
