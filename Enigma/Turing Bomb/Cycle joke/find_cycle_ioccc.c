static bool find_cycle(const uint8_t s,const uint8_t c,Tuple*t,const size_t n,
uint32_t m,int8_t*cp,size_t*i,int8_t*p){cp[(*i)++]=c;if(c==s&&*i>1)return 1;
for(size_t j=0;j<n;++j)if(!(m&(1<<j))){const uint8_t nl=(t[j].first==c)?t[j].
second:(t[j].second==c)?t[j].first:0;if(nl){m|=(1<<j);p[*i-1]=j;if(find_cycle(
s,nl,t,n,m,cp,i,p))return 1;m&=~(1<<j);p[*i-1]=-1;}}(*i)--;return 0;}
