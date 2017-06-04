cc = g++

objs = client.o errstr.o
exe = client

$(exe): $(objs)
	$(cc) $(objs) -o $@
client.o: client.cpp
	 $(cc) -c $< -o $@
errstr.o: errstr.cpp
	$(cc) -c $< -o $@

clean:
	rm -rf $(exe) *.o
