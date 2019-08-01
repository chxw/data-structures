#ifndef PAIR_HPP
#define PAIR_HPP

template<typename F, typename S>
class Pair{
public:
  Pair();
  Pair(F first, S second);
  Pair(const Pair<F, S>& other);
  Pair<F, S>& operator=(const Pair<F, S>& other);
  ~Pair();

  F getFirst() const;
  S getSecond() const;

private:
  F first;
  S second;
};

#endif
