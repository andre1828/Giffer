execName = giffer

run :
	cc main.c  \
	`pkg-config --cflags --libs webkitgtk-3.0` \
	`pkg-config --cflags --libs libcurl` -o $(execName).out \
	
	./$(execName).out   