static bool find_cycle(const uint8_t s, const uint8_t c, CharTuple*t, const uint8_t n, uint32_t v, CycleOld*y)
{y->chars_w_stubs[y->len_w_stubs]=c;y->chars_wo_stubs[y->len_wo_stubs]=c;if(c==s&&y->len_w_stubs>1)return 1;
for(uint8_t i=0;i<n;++i){if(!(v&(1<<i))){const uint8_t z=(t[i].first==c?t[i].second:(t[i].second==c?t[i].first:0));
if(z){v|=(1<<i);y->positions_w_stubs[++y->len_w_stubs]=i;y->positions_wo_stubs[++y->len_wo_stubs]=i;if(f(s,z,t,n,v,y))
return 1;v&=~(1<<i);}}}y->len_wo_stubs--;return 0;}
