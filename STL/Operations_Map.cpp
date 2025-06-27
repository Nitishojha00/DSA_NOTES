1. map (Ordered Map)

| Operation            | Code                        | Meaning                         |
| -------------------- | --------------------------- | ------------------------------- |
| Insert / Update      | `mp[5] = 100;`              | Insert key `5` with value `100` |
| Insert (safe)        | `mp.insert({3, 10});`       | Inserts only if `3` not present |
| Access               | `mp[3]`                     | Get value of key `3`            |
| Count (exists?)      | `mp.count(3)`               | `1` if key exists, else `0`     |
| Erase key            | `mp.erase(3);`              | Removes key `3`                 |
| Size                 | `mp.size()`                 | Total keys                      |
| Clear                | `mp.clear();`               | Removes all keys                |
| Find (iterator)      | `auto it = mp.find(5);`     | Points to key `5` or `mp.end()` |
| Loop over keys       | `for(auto [k,v] : mp)`      | Iterates in sorted order        |
| First / last element | `mp.begin()` / `--mp.end()` | Smallest / Largest key          |
| Lower Bound          | `mp.lower_bound(x)`         | First key `>= x`                |
| Upper Bound          | `mp.upper_bound(x)`         | First key `> x`                 |


2 . unordered_map

| Operation       | Code                     | Meaning                         |
| --------------- | ------------------------ | ------------------------------- |
| Insert / Update | `ump[2] = 50;`           | Insert/update key `2`           |
| Access          | `ump[2]`                 | Get value at key `2`            |
| Count           | `ump.count(2)`           | 1 or 0                          |
| Erase           | `ump.erase(2);`          | Remove key                      |
| Find            | `auto it = ump.find(2);` | Returns iterator or `ump.end()` |
| Loop            | `for(auto [k,v] : ump)`  | Order not guaranteed            |


3 . Ordered_set


| Operation      | Code                    | Meaning            |
| -------------- | ----------------------- | ------------------ |
| Insert         | `st.insert(5);`         | Insert element     |
| Count / Exists | `st.count(5)`           | 1 if exists        |
| Erase          | `st.erase(5);`          | Remove element     |
| Size           | `st.size()`             | Number of elements |
| Find           | `auto it = st.find(5);` | Iterator to 5      |
| Loop           | `for(int x : st)`       | In sorted order    |
| Lower Bound    | `st.lower_bound(x)`     | First `>= x`       |
| Upper Bound    | `st.upper_bound(x)`     | First `> x`        |



4. Unordered_set

| Operation      | Code                      | Meaning             |
| -------------- | ------------------------- | ------------------- |
| Insert         | `ust.insert(10);`         | Add 10              |
| Count / Exists | `ust.count(10)`           | 1 or 0              |
| Erase          | `ust.erase(10);`          | Remove element      |
| Find           | `auto it = ust.find(10);` | Iterator or `end()` |
| Loop           | `for(auto x : ust)`       | No guaranteed order |


 5- Indexed_set

| Operation                       | Code                  | Description                                         |
| ------------------------------- | --------------------- | --------------------------------------------------- |
| Insert                          | `s.insert(10);`       | Add element `10`                                    |
| Erase                           | `s.erase(10);`        | Remove element `10`                                 |
| Count (exists?)                 | `s.count(10);`        | Returns `1` if present, else `0`                    |
| Size                            | `s.size();`           | Total number of elements                            |
| Loop over elements              | `for (int x : s)`     | Iterates in ascending order                         |
| **Find kth smallest (0-based)** | `*s.find_by_order(k)` | Returns k-th smallest element                       |
| **Order of key (rank)**         | `s.order_of_key(x)`   | No. of elements strictly less than `x`              |
| Clear                           | `s.clear();`          | Erases all elements                                 |
| Lower Bound (≥ x)               | `s.lower_bound(x)`    | Iterator to first element ≥ x (use `find_by_order`) |
| Upper Bound (> x)               | `s.upper_bound(x)`    | Iterator to first element > x                       |
