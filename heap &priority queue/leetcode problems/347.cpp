class Solution
{
public:
    vector<int> nums;
    vector<int> ans;
    map<int, int> freq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (auto x : nums)
            freq[x]++;
        for (auto x : freq)
        {
            pq.push({x.second, x.first});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

Line - by - line Explanation 1️⃣ Function definition vector<int> topKFrequent(vector<int> &nums, int k)
{

    This function returns a vector of integers.

        Input :

        nums → the array of numbers

            k → how many most frequent numbers we want

        2️⃣ Create a frequency map
            unordered_map<int, int>
                freq;

    This creates a hash map :

        key = number

            value = how many times it appears

                Example :

        nums = [ 1, 1, 2, 3, 3, 3 ]

        freq = {
            1 → 2,
            2 → 1,
            3 → 3}

        3️⃣ Count each number for (int x : nums) freq[x]++;

    Loop through each element x in nums

        Increase its count in the map

            Equivalent to :

        freq[x] = freq[x] + 1

                  4️⃣ Create a min -
                  heap(priority queue)
                      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
                          pq;

    This is the most important line.

        What it means :

        priority_queue<...> → a heap

            it stores pairs : {frequency, number}

                              greater<pair<int, int>> → makes it a min -
        heap

            smallest frequency stays at top

                So :

        Top = element with smallest frequency in the heap

        5️⃣ Push each(frequency, number) into heap for (auto &p : freq)
    {

        p is a pair :

            p.first = number

                          p.second = frequency

                                         Push into heap : pq.push({p.second, p.first});

        We push :

            {frequency, number}

            Example 3 appears 5 times → push{5, 3}
                .

            6️⃣ Keep heap size = k if (pq.size() > k) pq.pop();

        This is the trick.

            If heap has more than k elements

                Remove the least frequent
                one(top of min - heap)

                    Why
            ?

            Because we want only the top k frequent elements.The min - heap automatically keeps the lowest freq on top.So removing top removes the “worst” candidate.

                                                                       Result
            :

            After processing all numbers,

            Heap contains exactly k numbers with highest frequency

            7️⃣ Extract results
                vector<int>
                    ans;

        Create answer vector.

            Pop elements from heap while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

    Remember:

        we stored pair{frequency, number}

            .second = number

                          .first = frequency

                                       We only need the numbers.

                                   8️⃣ Return result return ans;

        🎉 Final Summary(Very Simple)

                    Count frequencies

                        Use a min -
                heap of size k

                    Push{frequency, number}

                If heap grows >
            k,
            remove smallest frequency

                    Remaining are top -
                k most frequent

                Extract and return