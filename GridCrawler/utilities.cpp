template <class T> inline const T& max (const T& a, const T& b) {
  return (a<b)?b:a;     // or: return comp(a,b)?b:a; for version (2)
}

template <class T> inline const T& min (const T& a, const T& b) {
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}
