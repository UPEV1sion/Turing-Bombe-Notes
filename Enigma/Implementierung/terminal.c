typedef struct {
	uint8_t active_cable_connections[ALPHABET_SIZE];
	uint32_t active_bit_vector;
	uint8_t num_active_connections;
	uint8_t contact_num;
} Contact;

typedef struct {
	Contact *contacts[ALPHABET_SIZE];
	Contact *test_register;
} Terminal;

