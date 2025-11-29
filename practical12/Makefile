CFLAGS += -Wall -Wextra -Werror -std=c99 -O0 -g

e4: auth.o attack.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f e4 *.o