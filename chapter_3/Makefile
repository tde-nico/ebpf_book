TARGETS = hello hello-func

all: $(TARGETS)

$(TARGETS): %: %.bpf.o

%.bpf.o: %.bpf.c
	clang -target bpf -I/usr/include/$(shell uname -m)-linux-gnu -g -O2 -o$@ -c $<

clean:
	rm -rf *.bpf.o
	rm -rf /sys/fs/bpf/hello
	rm -rf /sys/fs/bpf/hello-func

load:
	sudo bpftool prog load hello.bpf.o /sys/fs/bpf/hello

.PHONY: all clean load
