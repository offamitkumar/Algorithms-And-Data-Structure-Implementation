void Log_Gen() { cerr << endl; }
template <typename HEAD, typename... TAIL>
void Log_Gen(HEAD H, TAIL... T) {
  cerr << " " << (H);
  Log_Gen(T...);
}
#ifdef HELL_JUDGE
#define Log(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define Log(...) 0
#endif
