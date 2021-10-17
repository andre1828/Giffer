execName = giffer

run :
	cc main.c  \
	`pkg-config --cflags --libs gtk3` \
	`pkg-config --cflags --libs libcurl` -o $(execName).out \
	
	./$(execName).out   