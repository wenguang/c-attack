
cc = gcc
objs = test.o cJSON.o
exe = test

$(exe): $(objs)
	$(cc) $(objs) -o $(@)
test.o: test.c
	$(cc) -c $< -o $(@)
cJSON.o: cJSON.c
	$(cc) -c $< -o $(@)

clean:
	rm -rf $(exe) *.o