cc = g++

objs = client.o errstr.o
exe = client

$(exe): $(objs)
	$(cc) $(objs) -o $@
client.o: client.c
	 $(cc) -c $< -o $@
errstr.o: errstr.c
	$(cc) -c $< -o $@

clean:
	rm -rf $(exe) *.o
