void mytemplate()
{
    int n;
    int l = 0 , r = 0;
    map or ans update according to condition
    while(r<n)
    {

        while(l<=r && condition not following)
        {
            l++;
        }
        r++;

    }
    
        return map/ans;
}

  I also see some good window implementation not sliding window only window is implementationse 

  void solve() {
    // Number of days in each month (non-leap year)
    vll month_days = {31,28,31,30,31,30,31,31,30,31,30,31};

    unordered_map<string, int> freq;
    string s;
    cin >> s;

    ll n = s.size();

    for (int i = 0; i + 9 < n; ++i) {
        string sub = s.substr(i, 10); // dd-mm-yyyy

        // Check format: 2 digits - 2 digits - 4 digits
        if (sub[2] != '-' || sub[5] != '-') continue;
        if (!isdigit(sub[0]) || !isdigit(sub[1]) || !isdigit(sub[3]) || !isdigit(sub[4])) continue;
        if (!isdigit(sub[6]) || !isdigit(sub[7]) || !isdigit(sub[8]) || !isdigit(sub[9])) continue;

        int day = (sub[0] - '0') * 10 + (sub[1] - '0');
        int month = (sub[3] - '0') * 10 + (sub[4] - '0');
        int year = stoi(sub.substr(6, 4));

        if (year < 2013 || year > 2015) continue;
        if (month < 1 || month > 12) continue;
        if (day < 1 || day > month_days[month - 1]) continue;

        freq[sub]++;
    }

    string most_frequent_date;
    int max_count = 0;

    for (auto &[date, count] : freq) {
        if (count > max_count) {
            max_count = count;
            most_frequent_date = date;
        }
    }

    cout << most_frequent_date << '\n';
}
