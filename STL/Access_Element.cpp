// ➡️ ++ on a reverse iterator actually moves backward in the original (normal) order.

// So:

// rbegin() points to index size() - 1

// ++rbegin() points to index size() - 2

// and so on…

auto it = container.rbegin();  // Points to LAST element
++it;                          // Now points to SECOND LAST element



  //  Example 1->  

       vector<int> v = {10, 20, 30, 40};
        auto it = v.rbegin();     // points to 40
        cout << *it << endl;      // 40
        ++it;                     // now points to 30
        cout << *it << endl;      // 30 ✅ VALID

   
  //  Example 2->  


       map<int, string> m = {  {1, "a"},  {2, "b"},  {3, "c"},  {4, "d"} };
        auto it = m.rbegin();
        auto [last_key, last_val] = *it;
        ++it;
        auto [second_key, second_val] = *it;

