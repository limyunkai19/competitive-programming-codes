# Solution

## Shopee Tanam
This is a classical dynamic programming problem.

For each row, we keep track of the best health we can obtain if we are at *left side* **and** *right side* of the park respectively.

Then we have the following recurrence relation.

```
best_left(row) = max(best_right(row-1) + sum(0, totalCol), max_across_i(best_left(row-1) + sum(row, 0, i)))
best_rigth(row) = max(best_left(row-1) + sum(0, totalCol), max_across_i(best_right(row-1) + sum(row, i, totalCol))

# base case
best_left(0) = max_across_i(sum(0, 0, i))
best_right(0) = sum(0, 0, totalCol)

where sum(r, c1, c2) returns the sum of all fruit on the r-th row, c1-th col to c2-th col (c2 non-inclusive), 0-indexed
```

See [shopee-tanam.cpp](shopee-tanam.cpp) for implementation in C++. For implementation in C++ or other statically-typed language, beware of the limit of `int32` as the answer will be larger than that, use `int64` instead.

## Shoffee
This is a non-straightforward and kind of a hard problem if we want to find a faster than `O(n^2)` solution.

In short, we want to find the number of subarray with an average value greater than or equal to a certain average, `v`. If we tackle the problem directly, it is very hard to optimize any further.

The crux idea and observation is, if we look on the value `b[i] = a[i] - v` the problem become

> find the number of subarray with sum greater than or equal to zero (`0`)

then the problem becomes easier to optimize as now we only have to deal with the sum, not average (which involves dividing by a variable number).

Now, prefix sum comes into play, in short we want to find number of `pair(i, j)` such that `prefixSum[j] - prefixSum[i] >= 0`. If `i` is constant, then the problem becomes counting the number of `j >= i` such that `prefixSum[j] >= prefixSum[i]`.

This can be done efficiently with an augmented balanced binary search tree that supports `O(log n)` value insertion and deletion, `O(log n)` counting the number of item greater than a certain value.

The pseudocode is
```python
# assume prefixSum[i] is ready
for i in range(0, n):
    bst.insert(prefixSum[i])

ans, pre = 0, 0
for i in range(0, n):
    ans += bst.countGreaterOrEqual(pre)
    bst.remove(prefixSum[i]) # remove this since we want to count for j >= i only
    pre = prefixSum[i] # use for next iteration to compute number of j such that prefixSum[j] >= prefixSum[i]

return ans
```

In practice, we don't need to implement a full-fledged balanced binary search tree to do that, the same functionality can be achieved with [fenwick tree](shoffee.cpp) or [GNU C++ built-in PBDS data structure](shoffee.pbds.cpp).

## Order Delivery
This problem is a very straightforward min-cost flow problem. For those who never heard of min-cost flow, this problem can be very hard, but it is straightforward for those who had heard of it before.

In short, a [min-cost flow problem](https://en.wikipedia.org/wiki/Minimum-cost_flow_problem) is to find the cheapest possible way to send a certain amount of flow (usually the maximum flow) through a flow network.

For those who never heard of the flow network before, imagine a graph where each edge is like a water pipe with limited capacity. To send a flow through the water pipe, we have to pay a certain amount of money per unit of water. In the flow network, there will be a source with an unlimited amount of water supplies and a sink.

- *Max flow* problem is to find the maximum amount of water flow that can be sent from source to sink.
- *Min-cost flow* problem is to find the cheapest way to send that maximum amount of water flow from source to sink.

In particular to this problem, assume an imaginary source. For each warehouse, connect the source to the city with warehouse with an edge with the capacity equal to `the stock amount` and cost of `0`. Then, connect the city with warehouse to each other city with large enough capacity and cost of `delivery fee * shortest path from warehouse to that city`. At last, for each order, gather all the order amounts at each city first, then connect each city to the sink with the capacity equal to `total order` in that city and cost of `0`.

See [order-delivery.cpp](order-delivery.cpp) for implementation in C++.

## Divider
This seems to be a classical dynamic programming problem at first glance. However, the straightforward DP will have a time complexity of `O(kn^2)` which is not enough to pass the time limit. Some optimization technique on DP is needed to solve this problem within the time limit.

Let's solve the problem with classical dynamic programming first. Let `minNoise(i, g)` be the minimum noise we can achieve if we separate the `0` to `i` (inclusive) engineers with `g` groups. Then we have the following recurrence relation.

```
minNoise(i, g) = min_across_k(minNoise(k-1, g-1), cost(k, i))

# base case
minNoise(i, 1) = cost(0, i)

where cost(i, j) = (A[i] + A[i+1] + ... + A[j]) * (j - i + 1)
```

The time complexity is `O(kn^2)`. See [divider.slow.cpp](divider.slow.cpp) for implementation in C++.

### Divide and Conquer Optimization
To optimize the time complexity, we can use a technique called [divide and conquer optimization](https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html).

In this problem, let `bestK(i, g)` be the value of `k` that produces the value of `minNoise(i, g)`. Intuitively, `bestK` is the starting index of the last group to separate out from the `0` to `i` engineers, so it must satisfy `bestK(i, g) <= bestK(i+1, g)` for all `i`. This can be proven by contradiction, to understand that intuitively, if for `i+1`, we can split the last group out with smaller amount engineers, then that smaller amount of engineers will then produce a smaller amount of noise if we split them out during the computation of `i`, hence it is impossible for that to happen, a contradiction.

Now, we have satisfied the condition to use divide and conquer optimization which is `bestK(i, g) <= bestK(i+1, g)`, then we can use the technique to reduce the time complexity to `O(kn log n)`. Regarding why we can use divide and conquer optimization when the condition is satisfied or how the divide and conquer optimization works, read [here](https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html) or search on the Internet for more resources.

See [divider.cpp](divider.cpp) for implementation in C++. Since there is no test data provided to verify if my implementation is correct, I generated a [test case](divider.large.in) and run it using the slow solution to verify its correctness.
