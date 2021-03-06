# delblank:delblank.c
# 	gcc -g $^ -o $@

# shrinkconcatnate:shrinkconcatnate.c
# 	gcc -g $^ -o $@

# all:shrinkconcatnate

# %.o:%.c
# 	gcc -g $^ -o $@

# objects = shrinkconcatnate  
# all: $(objects) 
# $(objects): %.o: %.c
# 	echo $@
# 	$(CC) -c $(CFLAGS) $< -o $@
# 	$(CC) $@ -o $(objects)

CC = gcc
CFLAGS = -std=c99 -W -Wall # -g
CFLAGSS = -std=c99 -W # -g
LIBS = -lm

shrinkconcatnate : shrinkconcatnate.o  
	$(CC) $^ $(LIBS) -o $@  # -lcrypt -lssl -lcrypto # -g

%.o : %.c
	$(CC) $(CFLAGS) $< -c 