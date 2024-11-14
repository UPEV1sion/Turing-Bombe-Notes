typedef struct MenuNode MenuNode;
typedef struct CribCipherTuple CribCipherTuple;

struct MenuNode {
	CribCipherTuple *stubs;
	uint8_t num_stubs;
	char letter;
};

struct CribCipherTuple {
	MenuNode first;
	MenuNode second;
	uint8_t position;
	bool visited;
};
