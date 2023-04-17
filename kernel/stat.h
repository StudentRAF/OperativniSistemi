#define T_DIR  (1 << 0)   // Directory
#define T_FILE (1 << 1)   // File
#define T_DEV  (1 << 2)   // Device

struct stat {
	short type;  // Type of file
	int dev;     // File system's disk device
	uint ino;    // Inode number
	short nlink; // Number of links to file
	uint size;   // Size of file in bytes
};
