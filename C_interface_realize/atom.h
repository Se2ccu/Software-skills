#ifndef ATOM_INCLUDED
#define ATOM_INCLUDED

int Atom_length(const char *str);
const char *Atom_new(const char *str, int len);
const char *Atom_string(const char *str);
const char *Atom_int(long n);

#endif