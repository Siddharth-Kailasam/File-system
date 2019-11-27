Filesystem using FUSE.
Steps for execution -
1. chmod a+x Makefile
2. make
3. ./ssfs -f <folder_to_mount>
Eg - ./ssfs -f Folder

You will now see that the folder 'Folder' is mounted using the filesystem written in the code.
You are now ready to explore the filesystem using the UI or the terminal. 
Termination could be done by pressing ctrl+c.
Persistence is implemented using this file called file.txt where the last used contents are written into the filesystem.

Refer to report.docx for more details on the project and imp.txt for implementation details. test.c contains a simple C code to test the filesystem assuming that the name of the mounted folder is called 'Folder'
