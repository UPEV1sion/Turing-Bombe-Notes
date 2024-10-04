#include "turing_bomb/cycle_finder/cycle_finder_graph.h"
#include "turing_bomb/cycle_finder/cycle_finder.h"

#include <time.h>

#define NUM_TESTS 1000
#define ALPHABET_SIZE 26

void generate_cipher(const char *crib, char *ciphertext, const size_t length) {
    for (size_t i = 0; i < length; ++i) {
        ciphertext[i] = crib[rand() % length];
    }
    ciphertext[length] = 0;
}

int main(void)
{

    for (size_t len = 2; len <= MAX_CRIB_LEN; ++len) {
        char crib[MAX_CRIB_LEN + 1];
        char ciphertext[MAX_CRIB_LEN + 1];

        for (size_t i = 0; i < len; ++i) {
            crib[i] = 'A' + (i % ALPHABET_SIZE);
        }
        crib[len] = 0;

        double total_time_graph = 0.0;
        double total_time_force = 0.0;

        for (int trial = 0; trial < NUM_TESTS; ++trial) {
            generate_cipher(crib, ciphertext, len);

            for (int i = 0; i < NUM_TESTS; ++i)
            {
                const clock_t start = clock();
                CycleCribCipher* result = find_best_cycle_graph(crib, ciphertext);
                const clock_t end = clock();
                total_time_graph += (double)(end - start) / CLOCKS_PER_SEC;
                if(result)
                    free(result);
            }


            for (int i = 0; i < NUM_TESTS; ++i)
            {
                const clock_t start = clock();
                CyclesCribCipher* result = find_cycles(crib, ciphertext);
                const clock_t end = clock();
                total_time_force += (double)(end - start) / CLOCKS_PER_SEC;

                free(result);
            }
        }

        const double avg_time_graph = total_time_graph / (NUM_TESTS * NUM_TESTS);
        const double avg_time_force = total_time_force / (NUM_TESTS * NUM_TESTS);

        printf("%.8f, %.8f\n", avg_time_graph, avg_time_force);
    }
	
	return 0;
}
