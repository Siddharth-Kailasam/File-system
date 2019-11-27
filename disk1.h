#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include<time.h>

#define BLOCK_SIZE 2048
#define T_BLOCKS 16
struct fileinfo
{
	int fileId;
	off_t offset;
	size_t size;
	mode_t mode;
	blkcnt_t blockcount;
	blksize_t block_size;
	int blockno[T_BLOCKS];
	int uid;
	int gid;
};

struct file
{
	char fname[50];	
	struct fileinfo *fil;
	unsigned int  fd_count;
};
	
struct directry
{
	char dname[50];
	int dirId;
	mode_t mode;
	struct file **f;
	int filecount;
	struct directry *next;
	int uid;
	int gid;
};

struct block
{
	int blockno;
	int valid;
	void * data;
	size_t size;
	size_t current_size;
};




struct superblock
{
	int totalblocks;	
	int totalfreeb;
	int freeblocknos[T_BLOCKS];
};

struct root
{
	struct directry * dir;
	struct file ** files;
	int filecount;
	int dircount;
	int uid;
	int gid;
	mode_t mode;
};
//#undef STRUCT_STAT
struct stats
{
	mode_t			st_mode;
	ino_t			st_ino;
	dev_t			st_dev;
	dev_t			st_rdev;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	struct timespec	st_atim;
	struct timespec	st_mtim;
	struct timespec st_ctim;
	blksize_t		st_blksize;
	blkcnt_t		st_blocks;
};


struct block **blocks;	
struct superblock super;		
struct root *fileroot;

int searchroot(const char *path,struct file **file_t,struct directry **dir,int s);
int searchdir(struct directry * d,const char *name,struct file **file_t);
int intialize();

int read_block(int blocknr, char *buf,off_t new_off,off_t off,size_t n);
int write_block(int blocknr,const char *buf,off_t new_off,off_t off,size_t n);


