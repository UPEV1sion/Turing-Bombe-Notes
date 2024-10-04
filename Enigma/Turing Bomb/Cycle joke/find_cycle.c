sstatic bool find_cycle(const uint8_t start, const uint8_t c,
                       CharTuple *restrict tuples, const uint8_t tuples_len,
                       uint32_t visited_mask, CycleCribCipher *restrict cycle)
{
    cycle->chars_w_stubs[cycle->len_w_stubs]   = c;
    cycle->chars_wo_stubs[cycle->len_wo_stubs] = c;

    if (c == start && cycle->len_w_stubs > 1)
    {
        return true;
    }

    for (uint8_t i = 0; i < tuples_len; ++i)
    {
        if (!(visited_mask & (1 << i)))
        {
            const uint8_t next_letter = (tuples[i].first == c)
                                            ? tuples[i].second
                                            : (tuples[i].second == c)
                                                  ? tuples[i].first
                                                  : 0;
            if (next_letter != 0)
            {
                visited_mask |= (1 << i);

                cycle->positions_w_stubs[cycle->len_w_stubs++]   = i;
                cycle->positions_wo_stubs[cycle->len_wo_stubs++] = i;

                if (find_cycle(start, next_letter, tuples, tuples_len, visited_mask, cycle))
                {
                    return true;
                }

                visited_mask &= ~(1 << i);
            }
        }
    }

    cycle->len_wo_stubs--;

    return false;
}