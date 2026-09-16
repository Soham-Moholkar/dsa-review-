"""Large regressions for counting algorithms; skip quadratic teaching baselines."""
def checks(name, namespace, level):
    if level == 2:
        return []
    if name == 'GFG_Frequencies_in_a_Limited_Array':
        return [f'''{{
            context = "{name} / level {level}: 50000 equal values";
            vector<int> a(50000, 50000), expected(50000, 0);
            expected.back() = 50000;
            {namespace}::Solution().frequencyCount(a, 50000, 50000);
            check(a == expected);
        }}''']
    if name == 'GFG_Find_Duplicates_in_an_Array':
        return [f'''{{
            context = "{name} / level {level}: 50000 zeros";
            vector<int> a(50000, 0);
            auto answer = {namespace}::Solution().findDuplicates(a);
            check(answer == vector<int>{{0}});
        }}''']
    return []
