static int find_cycle(uint8_t s,uint8_t c,CharTuple*t,uint8_t l,uint32_t v,CycleCribCipher*y){
y->chars_w_stubs[y->len_w_stubs]=c;y->chars_wo_stubs[y->len_wo_stubs]=c;if(c==s&&y->len_w_stubs>1)return 1;
for(uint8_t i=0;i<l;++i)if(!(v&(1<<i))){uint8_t n=(t[i].first==c)?t[i].second:(t[i].second==c)?t[i].first:0;
if(n){v|=(1<<i);y->positions_w_stubs[y->len_w_stubs++]=i;y->positions_wo_stubs[y->len_wo_stubs++]=i;if(
find_cycle(s,n,t,l,v,y))return 1;v&=~(1<<i);}}y->len_wo_stubs--;return 0;}
