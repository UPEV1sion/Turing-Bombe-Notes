static void activate_contact(TuringBombe *turing_bombe, 
							 uint8_t first_contact, 
							 uint8_t second_contact)
{
	Contact *primary_contact = turing_bombe->terminal->contacts[first_contact];
	Contact *secondary_contact = turing_bombe->terminal->contacts[second_contact];

	primary_contact->active_cable_connections[primary_contact->num_active_connections] = second_contact;
	secondary_contact->active_cable_connections[secondary_contact->num_active_connections] = first_contact;

	primary_contact->active_bit_vector |= (1 << second_contact);
	secondary_contact->active_bit_vector |= (1 << first_contact);

	primary_contact->num_active_connections++;
	secondary_contact->num_active_connections++;
}