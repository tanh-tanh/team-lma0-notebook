/*
 Vi du: prefix sum nhung can update va goi ra trong log(n)
 bit.set(n); giong bit.push_back()
 bit.pref_sum(n); goi ra tong cong don den n
 bai nay ko the lam bai range minium vi no update tu 0..n
*/
template <class T> class BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;

  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    void set(int ind, T val) { add(ind, val - arr[ind]); }

    void add(int ind, T val) {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
    }

    T pref_sum(int ind) {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
        return total;
    }
};
