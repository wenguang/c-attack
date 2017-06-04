
cc = g++
objs = server.o errstr.o
exe = server

$(exe): $(objs)
	$(cc) $(objs) -o $(@)
imserver.o: server.c
	$(cc) -c $< -o $@
errstr.o: errstr.c
	$(cc) -c $< -o $@

#.PHONY clean
clean:
	rm -rf $(exe) *.o
