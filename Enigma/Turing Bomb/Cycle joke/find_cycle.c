static bool find_cycle(const uint8_t start, const uint8_t c,
                     Tuple *tuples, const size_t tuples_len,
                     uint32_t visited_mask, int8_t *cycle_path,
                     size_t *cp_index, int8_t *positions)
{
    cycle_path[(*cp_index)++] = c;

    if (c == start && *cp_index > 1)
    {
        return true;
    }

    for (size_t i = 0; i < tuples_len; ++i)
    {
        if (!(visited_mask & (1 << i)))
        {
            // I know...
            const uint8_t next_letter = (tuples[i].first == c)
                                       ? tuples[i].second
                                       : (tuples[i].second == c)
                                             ? tuples[i].first
                                             : 0;
            if (next_letter != 0)
            {
                visited_mask |= (1 << i);
                positions[*cp_index - 1] = i;

                if (find_cycle(start, next_letter, tuples, tuples_len, visited_mask, cycle_path, cp_index, positions))
                {
                    return true;
                }

                visited_mask &= ~(1 << i);
                positions[*cp_index - 1] = -1;
            }
        }
    }

    (*cp_index)--;

    return false;
}