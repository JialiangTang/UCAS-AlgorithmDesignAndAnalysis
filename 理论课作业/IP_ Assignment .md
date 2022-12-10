# Algorithm Design and Analysis - Assignment 4

## 2020K8009907032

## 唐嘉良

### 2022年12月10日





### Problem1

**Analysis**：Assume $x_{ij}=1$ means j-th job is assigned to i-th worker. Vice versa.

then we have:  

$min\space max_{i}\sum_{j=1}^{n}{C_{ij}x_{ij}}$

$s.t. \sum_{i=1}^{m}{x_{ij}} = 1$ for all $j$

$x_{ij} = 0/1$ for all $i$ and $j$





### Problem2

**Analysis**：Assume $x_{i}=1$ means $i$-th food is bought. Vice versa. At the same time, we say the nutrition is satisfied when it is greater than 0.

then we have:  

$min \sum_{i=1}^{m}{C_{i}x_{i}}$

$s.t. \sum_{i=1}^{m}{x_{i}W_{ij}}>0$ for all $j$

$x_{i} = 0/1$ for all $i$ 



### Problem3

**Analysis**：Assume $x_{ij}$ is the amount of A of i-th place that is delivered to j-th market. Assume that the balance is achieved if and only if all A delivered is below the sum-output and all A accepted is below the sum-demand.

then we have:  

$min \sum_{i=1}^{n}\sum_{j=1}^{m}{C_{ij}x_{ij}}$

$s.t. \sum_{j=1}^{m}{x_{ij}} \le a_i$ for all $i$

$\sum_{i=1}^{n}{x_{ij}} \le b_i$ for all $j$

$x_{ij} \ge 0$ for all $i$ and $j$





### Problem4

**Analysis**：Assume $x_{ij}=1$ means i-th stuff is packed into j-th box. Vice versa.

then we have:  

$min \sum_{j=1}^{n}\vee_{i=1}^{m}{x_{ij}}$

$s.t. \sum_{j=1}^{n}{x_{ij}} \le 1$ for all $i$

$\sum_{i=1}^{n}{x_{ij}C_{i}} \le S_j$ for all $j$

$x_{ij} = 0/1$ for all $i$ and $j$





### Problem6

**Analysis**：Assume $x_{i}=1$ means $i$-th project is fund. Vice versa. 

then we have:  

$max \sum_{i=1}^{n}{(c_{i}-b_i)x_{i}}$

$s.t. \sum_{i=1}^{n}{x_{i}b_{i}}\le B$ 

$x_{i} = 0/1$ for all $i$ 





### Problem 7

**Analysis**：Assume we bulid $x$ A-dorms and $y$ B-dorms. Assume that profit is sum of $c_i$.

then we have:  

$max\space xc_i+yc_j$

$s.t. x \le n_i$ 

$y \le n_j$

$xs_i + ys_j\le s$

$x,y\ge 0$ 





### Problem 8

**Analysis**：Assume $x_i=1$ means place $A_i$ is chosen. Vice versa.

then we have:  

$max\sum_{i=1}^{7}{(c_{i}-b_i)x_{i}}$

$s.t.  \sum_{i=1}^{7}{x_{i}b_{i}}\le B$ 

$x_1+x_2+x_3\le2$

$x_4+x_5\ge 1$

$x_6 + x_7 \le 1$

$x_{i} = 0/1$ for all $i$





### Problem 9

**Analysis**：Assume $x_i=1$ means i-th item is packed. Vice versa. Assume there are n items in total.

then we have:  

$max\sum_{i=1}^{n}{c_{i}x_{i}}$

$s.t.  \sum_{i=1}^{n}{x_{i}a_{i}}\le b$ 

$x_{i} = 0/1$ for all $i$





### Problem 10

**Analysis**：Assume $x_{ij}=1$ means j-th job is assigned to i-th worker. Vice versa. Assume that num of jobs is less than num of workers, and there are m workers and n jobs.  So m$\le$n.

then we have:  

$max \sum_{i=1}^{m}\sum_{j=1}^{n}{c_{ij}x_{ij}}$

$s.t. \sum_{i=1}^{m}{x_{ij}} = 1$ for all $j$

$\sum_{j=1}^{n}{x_{ij}} = 1$  for all $i$

$x_{ij} = 0/1$ for all $i$ and $j$

