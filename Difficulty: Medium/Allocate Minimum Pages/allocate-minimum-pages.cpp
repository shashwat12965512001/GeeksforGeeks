class Solution {
  public:
  
    int feasible(int A[], int N, long mid) {
        int c = 1;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum > mid) {
                c++;
                sum = A[i];
            }
        }
        return c;
    }
    
    int findPagesHelper(int A[], int N, int M) {
        if (M > N) {
            return -1;
        }
        int l = INT_MIN;
        long r = 0;
        for (int i = 0; i < N; i++) {
            l = max(l, A[i]);
            r += A[i];
        }
        int ans = 0;
        while (l <= r) {
            long mid = (l + r) >> 1;
            if (feasible(A, N, mid) <= M) {
                ans = mid;
                r = mid-1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    int findPages(vector<int> &arr, int k) {
        int N = arr.size();
        int M = k;
        return findPagesHelper(arr.data(), N, M);
    }
};