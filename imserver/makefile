
cc = gcc
objs = imserver.o errstr.o
exe = imserver

$(exe): $(objs)
	$(cc) $(objs) -o $(@)
imserver.o: imserver.c
	$(cc) -c $< -o $@
errstr.o: errstr.c
	$(cc) -c $< -o $@

#.PHONY clean
clean:
	rm -rf $(exe) *.o
