/*
 Vi du: prefix sum nhung can update va goi ra trong log(n)
 nho khai bao BIT<int> bit
 bit.set(i,n); thay the phan tu o i thanh gia tri n
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
    //tim min p sao cho sum(p) >= sum neu ko co thi kq = n-1
    int lower_bound(T sum) {
        int highest_one_bit = 1;
        while (highest_one_bit << 1 <= bit.size())
            highest_one_bit <<= 1;
        int pos = 0;
        for (size_t blockSize = highest_one_bit; blockSize != 0; blockSize >>= 1) {
            int p = pos + blockSize ;
            if (p < bit.size() && bit[p] < sum) {
                sum -= bit[p];
                pos += blockSize;
            }
        }
        return pos;
    }
};
