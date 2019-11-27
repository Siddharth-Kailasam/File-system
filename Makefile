CFLAGS += -D_FILE_OFFSET_BITS=64
COMPILER = gcc
FILESYSTEM_FILES = disk7.c

build: $(FILESYSTEM_FILES)
	$(COMPILER) $(FILESYSTEM_FILES) -lm -o ssfs `pkg-config fuse --cflags --libs`
	echo 'To Mount: ./ssfs -f [mount point]'

clean:
	rm ssfs
